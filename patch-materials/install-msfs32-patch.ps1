$ErrorActionPreference = 'Stop'

$isAdmin = ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole(
    [Security.Principal.WindowsBuiltInRole]::Administrator
)
if (-not $isAdmin) {
    throw 'Run this script as Administrator.'
}

$target = 'C:\Windows\SysWOW64\MSFS32.DLL'
$source = Join-Path $PSScriptRoot 'MSFS32.patched.dll'
$backupDir = 'C:\DATA\outlook_backup\MSFS32'
$stamp = Get-Date -Format 'yyyyMMdd-HHmmss'
$backup = Join-Path $backupDir "MSFS32.dll.orig-$stamp"

if (Get-Process OUTLOOK -ErrorAction SilentlyContinue) {
    throw 'Outlook is still running. Exit Outlook first.'
}
if (-not (Test-Path -LiteralPath $source)) {
    throw "Patch file not found: $source"
}

New-Item -ItemType Directory -Force -Path $backupDir | Out-Null
Copy-Item -LiteralPath $target -Destination $backup -Force
Copy-Item -LiteralPath $source -Destination $target -Force

$patchedHash = (Get-FileHash -LiteralPath $target -Algorithm SHA256).Hash
$originalHash = (Get-FileHash -LiteralPath $backup -Algorithm SHA256).Hash

Write-Host "Original backup: $backup"
Write-Host "Backup SHA256: $originalHash"
Write-Host "Current SHA256: $patchedHash"

if ($patchedHash -ne '213CA1197880B20C8984B3EC5375D680D54FF01E7B808459E8C1D69672F744B9') {
    throw 'Patched DLL hash mismatch.'
}

Write-Host 'Install complete. Restart Outlook.'
Write-Host 'Run uninstall-msfs32-patch.ps1 to roll back.'
