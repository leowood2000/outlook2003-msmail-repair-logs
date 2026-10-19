# MSFS32.dll 补丁分析材料包
打包时间：2026-10-19 | 来源：本机 C:\Windows\SysWOW64\MSFS32.DLL 分析副本

> 2026-10-19 17:30 更新：已制作 2 字节止血补丁并通过 Office11 本地副本验证加载。
> 补丁文件：`MSFS32.patched.dll`；说明：`README-msfs32-patch.md`；副作用与证据：根目录《MSFS32-2字节止血补丁与副作用-20261019.md》。

## 文件清单与哈希

| 文件 | 大小 | 说明 |
|---|---|---|
| MSFS32.dll | 500 KB (512,000 B) | 原始 DLL 副本，v5.5.2803.0，文件日期 1999-02-24 |
| crashfunc.c | 19 KB | Ghidra 12.1.4 反编译的崩溃函数 FUN_6f84dc40 全文 |
| crashsite_run.log | 88 KB | Ghidra 运行日志：崩溃函数 DIS 反汇编 + C 代码 + MAPIFreeBuffer 全部 10 个调用点与调用链 |
| ghidra_run.log | 14 KB | Ghidra 导入/自动分析日志（含 RVA 换算依据） |
| windbg_analyze.txt | 9 KB | !analyze -v 完整判词（HEAP_CORRUPTION BlockNotBusy DOUBLE_FREE） |
| windbg_stack.txt | 6 KB | .ecxr 崩溃现场调用栈（MSFS32!Ordinal10+0x10a8d 帧） |
| cdb_stackscan.txt | 11 KB | 崩溃线程栈内存原始转储（含 RtlpHeapFailureInfo 结构，"堆信息"） |
| cdb_deep.txt | 14 KB | 深度栈扫描：全部 MSFS32/MSMAPI32/MSPST32 栈上地址 + 堆失败结构体 dump |
| cdb_static.txt | 5 KB | 崩溃调用点静态反汇编（0x6f84e4a0-0x6f84e510） |

**MSFS32.dll SHA256**（与系统原件逐字节一致，分析未被篡改）：
`29040449ED5FD2A95AEBCF1FD787AE65FACDA457F46FC957222ACAF8D695F20F`

## 关键地址与证据速查（省你重算）

- 模块基址（转储中）：0x6F820000
- Ordinal10（无名序号导出）：RVA 0x1DA60
- 崩溃返回地址：0x6f84e4ed → RVA **0x2E4ED**
- 崩溃调用指令：RVA **0x2E4EA**（call [eax+4]）
- 所在函数：FUN_6f84dc40，RVA 0x2DC40 ~ 0x2E5C4（MS Mail 入站投递的 MAPI 表格/行集处理循环）
- 崩溃点指令字节（静态确认）：
  ```
  0x2E4E3: 8B 4B 08           mov ecx,[ebx+8]
  0x2E4E6: 8B 46 08           mov eax,[esi+8]
  0x2E4E9: 51                 push ecx
  0x2E4EA: FF 50 04           call dword ptr [eax+4]   ; MAPIFreeBuffer，崩溃在此调用内部
  0x2E4ED: 8B 44 24 20        mov eax,[esp+20h]        ; 返回地址
  ```
- 后续同模式释放：0x2E4F5（call [edx+4]，F(local_260)）、0x2E50E（同模式）
- 错误统一出口：LAB_6f84e550（RVA 0x2E550），函数内有十多处 goto 指向它
- MAPIFreeBuffer thunk @ 0x6f88682c（IAT 槽）；MSFS32 内 10 处调用点：
  FUN_6f8619f0(×2: 0x6f861ae9/0x6f861af3)、FUN_6f861f50(0x6f861ff4)、FUN_6f862180(0x6f8621e5)、
  FUN_6f85a4c0(0x6f85a518)、FUN_6f85a560(0x6f85a565)、未定位函数(0x6f861ba0/0x6f861b56/0x6f88334f/0x6f883526)

## 已确认/已排除（来自 2026-10-19 逆向 + ChatGPT-6 High 审核）

已确认：
1. 崩溃发生在 0x2E4EA 这次释放**内部**——被释放的指针在到达此点**之前**就已经失效（非"本函数内释放两次"的顺序）
2. [eax+4] 是 MAPI allocator 的 FreeBuffer 虚表槽（崩溃栈 MAPIFreeBuffer+0x62 动态证实）
3. F(piVar12[2]) 与 F(local_260) 是 SRow.lpProps（行属性数组）与 SRowSet（行集）两块不同内存，先后释放属 MAPI 规范正常顺序，**不是** double-free 证据

仍待查（补丁方向）：
1. 首次释放发生在哪——候选：前一轮循环迭代残留、被调函数（FUN_6f852360 / FUN_6f84e5d0 / FUN_6f83fbb0 等）提前释放了 lpProps、指针别名
2. 全部释放点（10 处 MAPIFreeBuffer 调用）的完整控制流可达性（CFG）
3. 检查是否堆元数据先被越界写/UAF 破坏，释放时才检测到

## 隐私声明

512MB 完整转储按约定未包含（内含私人邮件数据）。本包内全部日志已扫描：零中文残留、零邮箱地址（@ 符号均为 WinDbg 寄存器语法）。MSFS32.dll 为系统二进制，无任何个人数据。

## 修复管线约定（双方已同意）

1. ~~确认崩溃调用位置~~ 完成
2. 指针生命周期与重复释放路径分析 ← **当前步骤**
3. 必要时 PageHeap 动态取证（gflags /p /enable OUTLOOK.EXE /full，隔离环境）
4. 最小机器码补丁设计 + DLL 完整性校验（保留原版可回滚）
5. 隔离环境实测收发邮件与崩溃消失验证
