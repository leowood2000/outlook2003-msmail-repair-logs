# MSFS32.dll 2 字节止血补丁说明

日期：2026-10-19

## 这个补丁做什么

崩溃点固定在：

```text
MSFS32!Ordinal10+0x10A8D  (RVA 0x2E4ED)
调用点 RVA 0x2E4EA: call dword ptr [eax+4]  ; MAPIFreeBuffer(lpProps)
```

转储显示，执行到这次释放时，`lpProps` 堆块已经是 `LFH;free`，行集本身仍是 busy。也就是说 `lpProps` 在更早的时候已经被释放过一次。

补丁把 RVA `0x2E4E3` 的：

```text
8B 4B 08   mov ecx,[ebx+8]
```

改成：

```text
EB 08      jmp short 0x2E4ED
```

这样会跳过本次 `lpProps` 的释放，直接执行后面的行集释放。栈保持平衡，行集仍会正常释放。

## 文件

| 文件 | SHA256 |
|---|---|
| 原版 `MSFS32.dll` | `29040449ED5FD2A95AEBCF1FD787AE65FACDA457F46FC957222ACAF8D695F20F` |
| 补丁版 `MSFS32.patched.dll` | `213CA1197880B20C8984B3EC5375D680D54FF01E7B808459E8C1D69672F744B9` |

补丁后字节（文件偏移 `0x2E4E3`）：

```text
EB 08 08 8B 46 08 51 FF
```

PE 校验和已重算。

## 测试方法

### 方案 A：先放 Office 目录（不改系统文件，推荐先试）

1. 完全退出 Outlook。
2. 把 `MSFS32.patched.dll` 复制为：

```text
C:\Program Files (x86)\Microsoft Office\OFFICE11\MSFS32.dll
```

3. 启动 Outlook，用调试器确认加载的是本地副本：

```text
cdbX86 -p <OutlookPID> -c "lm m MSFS32; qd"
```

如果显示 `...\OFFICE11\MSFS32.dll`，说明本地副本生效；如果仍显示 `C:\WINDOWS\SYSTEM32\MSFS32.DLL`，说明加载顺序没有走本地副本，改用方案 B。

### 方案 B：替换系统 DLL（需要管理员，先备份）

运行 `install-msfs32-patch.ps1`（会要求 UAC）。脚本会：

- 检查 Outlook 已退出；
- 把原版备份到 `C:\DATA\outlook_backup\MSFS32\`；
- 复制补丁版到 `C:\Windows\SysWOW64\MSFS32.DLL`；
- 校验收到的 SHA256。

回滚运行 `uninstall-msfs32-patch.ps1`，会从备份恢复原版并校验原版哈希。

## 代价与边界

- 这是**止血补丁**，不是根因修复。它跳过每次正常行的 `lpProps` 释放；如果该块本来有效，会泄漏该行属性块及其字符串。按崩溃频率看泄漏量不大，但长期运行需要观察 Outlook 内存。
- 只覆盖当前已观测到的崩溃点（`0x2E4EA` 的正常行释放路径）。错误出口和 `0x20000` 分支的其他释放点没有改。
- 不解决“第一次是谁释放了 lpProps”的根因；真正的根因定位仍建议用 `MAPIFreeBuffer` 日志/防重垫片，或继续静态分析 MSMAPI32 的表层。
- 原 DLL 没有数字签名，改文件不会破坏签名校验；但杀软可能对系统目录中被修改的 DLL 报警。

## 回滚

- 方案 A：删除 `C:\Program Files (x86)\Microsoft Office\OFFICE11\MSFS32.dll`。
- 方案 B：运行 `uninstall-msfs32-patch.ps1`，或从 `C:\DATA\outlook_backup\MSFS32\` 手动恢复原版。
