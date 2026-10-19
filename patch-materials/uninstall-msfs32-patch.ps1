$ErrorActionPreference = 'Stop'

$isAdmin = ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole(
    [Security.Principal.WindowsBuiltInRole]::Administrator
)
if (-not $isAdmin) {
    throw 'Run this script as Administrator.'
}

$target = 'C:\Windows\SysWOW64\MSFS32.DLL'
$backupDir = 'C:\DATA\outlook_backup\MSFS32'

if (Get-Process OUTLOOK -ErrorAction SilentlyContinue) {
    throw 'Outlook is still running. Exit Outlook first.'
}

$backup = Get-ChildItem -LiteralPath $backupDir -Filter 'MSFS32.dll.orig-*' |
    Sort-Object LastWriteTime -Descending |
    Select-Object -First 1
if (-not $backup) {
    throw "Original backup not found: $backupDir"
}

Copy-Item -LiteralPath $backup.FullName -Destination $target -Force
$hash = (Get-FileHash -LiteralPath $target -Algorithm SHA256).Hash

Write-Host "Restored: $($backup.FullName)"
Write-Host "Current SHA256: $hash"

if ($hash -ne '29040449ED5FD2A95AEBCF1FD787AE65FACDA457F46FC957222ACAF8D695F20F') {
    throw 'Restored DLL hash does not match the original.'
}

Write-Host 'Rollback complete. Restart Outlook.'
