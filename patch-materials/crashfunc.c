C 
C char * __fastcall FUN_6f84dc40(void *param_1)
C 
C {
C   int *piVar1;
C   void *this;
C   byte bVar2;
C   int *piVar3;
C   undefined1 uVar4;
C   ushort uVar5;
C   short sVar6;
C   char *pcVar7;
C   undefined4 *puVar8;
C   uint uVar9;
C   int iVar10;
C   undefined3 extraout_var;
C   int iVar11;
C   int *piVar12;
C   ushort *puVar13;
C   undefined4 local_270;
C   LPCSTR pCStack_26c;
C   ushort *puStack_268;
C   ushort *puStack_264;
C   int *local_260;
C   int *local_25c;
C   uint *local_258;
C   char *local_254;
C   int iStack_250;
C   uint uStack_24c;
C   LPCSTR pCStack_248;
C   LPCSTR pCStack_244;
C   uint uStack_240;
C   int iStack_23c;
C   int iStack_238;
C   undefined4 uStack_234;
C   ushort *puStack_230;
C   int local_22c;
C   undefined4 local_228;
C   int local_224;
C   char *pcStack_220;
C   int *piStack_21c;
C   uint uStack_218;
C   ushort *puStack_214;
C   undefined4 uStack_210;
C   undefined4 uStack_20c;
C   undefined4 uStack_208;
C   int iStack_204;
C   int iStack_200;
C   int iStack_1fc;
C   CHAR aCStack_1f8 [504];
C   
C   piVar12 = (int *)0x0;
C   this = *(void **)((int)param_1 + 8);
C   local_25c = (int *)0x0;
C   local_22c = 0;
C   local_260 = (int *)0x0;
C   local_258 = (uint *)0x0;
C   local_270 = 0;
C   local_228 = 0;
C   local_254 = (char *)0x0;
C   if (*(int *)((int)this + 0x5c) == 0x14955e5b) {
C LAB_6f84dc9d:
C     bVar2 = 0;
C   }
C   else {
C     if (*(int *)((int)this + 0x8c) == 0) {
C       iVar10 = 8;
C     }
C     else {
C       iVar10 = 9;
C     }
C     if ((*(uint *)((int)this + 0x88) >> iVar10 & 1) == 0) goto LAB_6f84dc9d;
C     bVar2 = 1;
C   }
C   pcVar7 = (char *)FUN_6f827160(this,&local_224,(-(uint)bVar2 & 0xfffff000) + 0x1000);
C   if (-1 < (int)pcVar7) {
C     *(undefined4 *)((int)param_1 + 0x1f8) = *(undefined4 *)(local_224 + 0x18);
C     puVar8 = FUN_6f8461d0(*(int **)((int)param_1 + 4));
C     *(undefined4 **)((int)param_1 + 0xac) = puVar8;
C     if (puVar8 == (undefined4 *)0x0) {
C       pcVar7 = (char *)0x8007000e;
C     }
C     else {
C       puVar8 = FUN_6f8461d0(*(int **)((int)param_1 + 4));
C       *(undefined4 **)((int)param_1 + 0xa4) = puVar8;
C       if (puVar8 == (undefined4 *)0x0) {
C         pcVar7 = (char *)0x8007000e;
C       }
C       else {
C         puVar8 = FUN_6f8461d0(*(int **)((int)param_1 + 4));
C         *(undefined4 **)((int)param_1 + 0x18c) = puVar8;
C         if (puVar8 == (undefined4 *)0x0) {
C           pcVar7 = (char *)0x8007000e;
C         }
C         else {
C           puVar8 = FUN_6f8461d0(*(int **)((int)param_1 + 4));
C           *(undefined4 **)((int)param_1 + 400) = puVar8;
C           if (puVar8 == (undefined4 *)0x0) {
C             pcVar7 = (char *)0x8007000e;
C           }
C           else {
C             local_254 = (char *)(**(code **)(**(int **)((int)param_1 + 0x9c) + 0x48))
C                                           (*(int **)((int)param_1 + 0x9c),0,&local_25c);
C             if (((((-1 < (int)local_254) &&
C                   (local_254 = (char *)HrAddColumns(local_25c,&DAT_6f8232d0,
C                                                     *(undefined4 *)(*(int *)((int)param_1 + 8) + 8),
C                                                     *(undefined4 *)(*(int *)((int)param_1 + 8) + 4))
C                   , -1 < (int)local_254)) &&
C                  (local_254 = (char *)(**(code **)(*local_25c + 0x24))(local_25c,0,&local_22c),
C                  -1 < (int)local_254)) &&
C                 ((*(int *)((int)param_1 + 0x1bc) != 0 ||
C                  (pcVar7 = (char *)(**(code **)(*(int *)((int)param_1 + 8) + 8))
C                                              (local_22c * 4,(int)param_1 + 0x214), -1 < (int)pcVar7)
C                  ))) && (local_254 = (char *)(**(code **)(*local_25c + 0x20))
C                                                        (local_25c,1,&local_228), -1 < (int)local_254
C                         )) {
C               iVar10 = *(int *)((int)param_1 + 8);
C               pcVar7 = (char *)CreateTable(&DAT_6f822ef0,*(undefined4 *)(iVar10 + 8),
C                                            *(undefined4 *)(iVar10 + 0xc),*(undefined4 *)(iVar10 + 4)
C                                            ,*(undefined4 *)(iVar10 + 0x10),2,0x30000003,local_228,
C                                            (int)param_1 + 0x20c);
C               if (-1 < (int)pcVar7) {
C LAB_6f84de28:
C                 piVar12 = (int *)0x0;
C                 puStack_268 = (ushort *)0x0;
C                 puStack_264 = (ushort *)0x0;
C                 pCStack_248 = (LPCSTR)0x0;
C                 pCStack_244 = (LPCSTR)0x0;
C                 pCStack_26c = (LPCSTR)0x0;
C                 puStack_230 = (ushort *)0x0;
C                 iStack_23c = 0;
C                 uStack_240 = 0;
C                 uStack_24c = 0;
C                 iStack_250 = 1;
C                 uStack_218 = 0;
C                 iStack_238 = 0;
C                 uStack_234 = 0;
C                 pcVar7 = (char *)FUN_6f84ba60((int)param_1);
C                 if (pcVar7 != (char *)0x0) goto LAB_6f84e550;
C                 local_258 = (uint *)0x0;
C                 local_270 = 0;
C                 local_254 = (char *)(**(code **)(*local_25c + 0x4c))(local_25c,1,0,&local_260);
C                 piVar3 = local_260;
C                 if ((int)local_254 < 0) goto LAB_6f84e550;
C                 if (*local_260 == 0) {
C                   (**(code **)(*local_25c + 8))(local_25c);
C                   local_25c = (int *)0x0;
C                   if ((*(int *)(*(int *)((int)param_1 + 0xac) + 8) != 0) &&
C                      (pcVar7 = (char *)FUN_6f851f60((int)param_1), -1 < (int)pcVar7)) {
C                     pcVar7 = (char *)FUN_6f851fa0((int)param_1);
C                   }
C                   goto LAB_6f84e550;
C                 }
C                 piVar12 = local_260 + 1;
C                 uVar9 = *(uint *)(local_260[3] + 0x50) & 0xffff;
C                 piStack_21c = piVar12;
C                 if ((uVar9 == 1) || (uVar9 == 10)) {
C                   local_270 = 3;
C                 }
C                 else {
C                   pCStack_248 = (LPCSTR)FUN_6f846190((uint *)(local_260[3] + 0x50),(uint *)0x0);
C                 }
C                 uVar9 = *(uint *)(piVar3[3] + 0x40) & 0xffff;
C                 if ((uVar9 != 1) && (uVar9 != 10)) {
C                   pCStack_26c = (LPCSTR)FUN_6f846190((uint *)(piVar3[3] + 0x40),(uint *)0x0);
C                 }
C                 uVar9 = *(uint *)(piVar3[3] + 0x30) & 0xffff;
C                 puVar13 = puStack_264;
C                 if ((uVar9 != 1) && (uVar9 != 10)) {
C                   puStack_268 = (ushort *)FUN_6f846190((uint *)(piVar3[3] + 0x30),(uint *)0x0);
C                   iVar10 = FUN_6f8497b0(0,(BYTE *)puStack_268);
C                   puVar13 = puStack_268;
C                   if (iVar10 == 0) {
C                     puStack_268 = (ushort *)0x0;
C                     puVar13 = puStack_268;
C                   }
C                 }
C                 pCStack_244 = pCStack_248;
C                 uVar9 = uStack_218;
C                 if (pCStack_26c != (LPCSTR)0x0) {
C                   uVar5 = FUN_6f83df00(pCStack_26c);
C                   uVar9 = (uint)uVar5;
C                 }
C                 if ((*(short *)(piVar3[3] + 0x28) == 0) &&
C                    ((sVar6 = (short)uVar9, sVar6 == 0x21 || (sVar6 == 0x15)))) {
C                   pcVar7 = FUN_6f840290(*(int *)((int)param_1 + 8),pCStack_248,puStack_268,sVar6,
C                                         &puStack_230,&iStack_1fc,(char *)0x0);
C                   if ((int)pcVar7 < 0) {
C                     iStack_250 = 0;
C                   }
C                   else {
C                     puStack_268 = puStack_230;
C                     pcVar7 = (char *)(**(code **)(*(int *)((int)param_1 + 8) + 8))(4,&pCStack_26c);
C                     if ((int)pcVar7 < 0) goto LAB_6f84e550;
C                     *(undefined4 *)pCStack_26c = DAT_6f823230;
C                     *(undefined4 *)((int)param_1 + 0x1d8) = 1;
C                   }
C                 }
C                 iVar10 = piVar3[3];
C                 uVar9 = *(uint *)(iVar10 + 0x60) & 0xffff;
C                 if ((uVar9 == 1) || (uVar9 == 10)) {
C                   local_270 = 3;
C                 }
C                 else {
C                   if (((*(short *)(iVar10 + 0x28) == 0) || (*(int *)((int)param_1 + 0x1bc) != 0)) &&
C                      (uVar4 = FUN_6f828f70(*(int *)(iVar10 + 0x6c),*(uint *)(iVar10 + 0x68)),
C                      CONCAT31(extraout_var,uVar4) == 0)) {
C                     iVar10 = piVar3[3];
C                     iStack_238 = *(int *)(iVar10 + 0x6c);
C                     uStack_234 = *(undefined4 *)(iVar10 + 0x68);
C                     pcVar7 = (char *)FUN_6f852550(*(int *)((int)param_1 + 8),iVar10,6,pCStack_26c,
C                                                   pCStack_248,(char *)puVar13,(undefined4 *)0x0);
C                     if ((int)pcVar7 < 0) {
C                       iStack_250 = 0;
C                     }
C                   }
C                   iStack_23c = *(int *)(piVar3[3] + 0x6c);
C                   uStack_240 = *(uint *)(piVar3[3] + 0x68);
C                 }
C                 uVar9 = *(uint *)(piVar3[3] + 0x80) & 0xffff;
C                 if ((uVar9 != 1) && (uVar9 != 10)) {
C                   *(undefined4 *)((int)param_1 + 0x1d8) = 1;
C                 }
C                 puStack_264 = *(ushort **)(piVar3[3] + 0x18);
C                 if (((*(int *)((int)param_1 + 0x1bc) == 0) ||
C                     (puStack_264 = (ushort *)((uint)puStack_264 & 0x7fffffff),
C                     *(int *)((int)param_1 + 0x1bc) == 0)) && (puStack_264 == (ushort *)0x3)) {
C LAB_6f84e0c7:
C                   if (puStack_264 == (ushort *)0x10000000) goto LAB_6f84e0cf;
C                 }
C                 else {
C                   if (puStack_264 != (ushort *)0x10000000) {
C                     pcVar7 = (char *)(**(code **)(**(int **)((int)param_1 + 0x20c) + 0x10))
C                                                (*(int **)((int)param_1 + 0x20c),piVar12);
C                     if (-1 < (int)pcVar7) goto LAB_6f84e0c7;
C                     goto LAB_6f84e550;
C                   }
C LAB_6f84e0cf:
C                   puStack_264 = (ushort *)0x3;
C                 }
C                 if (puStack_264 == (ushort *)0x3) {
C                   *(undefined4 *)((int)param_1 + 0x1d8) = 1;
C                 }
C                 iVar10 = *(int *)((int)param_1 + 0x1bc);
C                 if ((iVar10 != 0) && ((*(byte *)((int)param_1 + 0x1c4) & 8) != 0)) {
C                   local_270 = 3;
C                 }
C                 if ((iStack_250 != 0) && ((short)local_270 == 0)) {
C                   if ((iVar10 != 0) || (*(short *)(piVar3[3] + 0x28) == 0)) {
C                     if (*(int *)((int)param_1 + 0x200) != 0) {
C                       uStack_24c = uStack_24c | 0x1000000;
C                     }
C                     pcVar7 = (char *)FUN_6f852360(param_1,&uStack_24c,(undefined2 *)&local_270,
C                                                   iStack_23c,uStack_240,(int *)&pCStack_244,
C                                                   (int *)&pCStack_26c,(int *)&puStack_268,iVar10,
C                                                   (int *)&pcStack_220);
C                     if ((int)pcVar7 < 0) goto LAB_6f84e550;
C                   }
C                   if ((uStack_24c & 0x80000000) == 0) {
C                     iStack_250 = 0;
C                   }
C                   else {
C                     *(undefined2 *)(piVar3[3] + 0x28) = 1;
C                   }
C                   if (iStack_250 == 0) {
C LAB_6f84e208:
C                     *(undefined4 *)((int)param_1 + 0x1d8) = 1;
C                     if (piVar12 != (int *)0x0) {
C LAB_6f84e4e3:
C                       (**(code **)(*(int *)((int)param_1 + 8) + 4))(piVar12[2]);
C                     }
C LAB_6f84e4ed:
C                     (**(code **)(*(int *)((int)param_1 + 8) + 4))(local_260);
C                     goto LAB_6f84e4f8;
C                   }
C                   if (puStack_264 != (ushort *)0x3) goto LAB_6f84e200;
C                   piVar1 = (int *)((int)param_1 + 0x1d4);
C                   if (*(int *)((int)param_1 + 0x1d4) == 0) {
C                     pcVar7 = (char *)(**(code **)(*(int *)((int)param_1 + 8) + 8))
C                                                (local_22c * 0xc + 4,piVar1);
C                     if ((int)pcVar7 < 0) goto LAB_6f84e550;
C                     *(undefined4 *)*piVar1 = 0;
C                   }
C                   iVar10 = *(int *)*piVar1;
C                   ((int *)*piVar1)[iVar10 * 3 + 2] = piVar3[2];
C                   *(int *)(*piVar1 + (iVar10 + 1) * 0xc) = piStack_21c[2];
C                   *(int *)*piVar1 = *(int *)*piVar1 + 1;
C                   piVar12 = piStack_21c;
C                 }
C LAB_6f84e200:
C                 if (iStack_250 == 0) goto LAB_6f84e208;
C                 if (*(int *)((int)param_1 + 0xe4) == 0) {
C                   if (*(int *)((int)param_1 + 0x1c8) == 0) {
C                     if ((*(byte *)(*(int *)((int)param_1 + 8) + 0x3c) & 0x20) == 0) {
C                       local_270 = 0xc;
C                     }
C                   }
C                   else {
C                     local_270 = 8;
C                   }
C                 }
C                 else {
C                   local_270 = 0xe;
C                 }
C                 if ((short)local_270 != 0) {
C LAB_6f84e3c4:
C                   if ((short)local_270 != 0) {
C                     pcVar7 = (char *)FUN_6f84e5d0(*(int *)((int)param_1 + 8),
C                                                   *(undefined4 *)((int)param_1 + 0x1bc),local_270,
C                                                   *(char **)(piVar12[2] + 8),(char *)0x0,pCStack_26c
C                                                   ,(char *)puStack_268,(undefined4 *)pCStack_248,
C                                                   (char)*(undefined4 *)(piVar12[2] + 0x18),0x81,0,
C                                                   &local_258);
C                     if ((int)pcVar7 < 0) goto LAB_6f84e550;
C                     if (*(int *)((int)param_1 + 0x1bc) == 0) {
C                       pcVar7 = (char *)FUN_6f851f00((int)param_1);
C                     }
C                     else {
C                       pcVar7 = (char *)FUN_6f851a10(param_1,(byte *)&local_258);
C                     }
C                     if ((int)pcVar7 < 0) goto LAB_6f84e550;
C                     *(undefined4 *)((int)param_1 + 0x1d8) = 1;
C                   }
C                   if ((*(int *)((int)param_1 + 0x1bc) == 0) &&
C                      (((short)local_270 != 0 || (*(int *)((int)param_1 + 0x200) == 0)))) {
C                     iStack_204 = piVar12[1];
C                     iStack_200 = piVar12[2];
C                     uStack_20c = 1;
C                     uStack_208 = 0;
C                     if (iStack_238 != 0) {
C                       *(int *)(iStack_200 + 0x6c) = iStack_238;
C                       *(undefined4 *)(piVar12[2] + 0x68) = uStack_234;
C                     }
C                     local_254 = (char *)(**(code **)(**(int **)((int)param_1 + 0x9c) + 0x4c))
C                                                   (*(int **)((int)param_1 + 0x9c),4,&uStack_20c);
C                     *(undefined4 *)
C                      (*(int *)((int)param_1 + 0x214) + *(int *)((int)param_1 + 0x210) * 4) =
C                          *(undefined4 *)(piVar12[2] + 8);
C                     *(int *)((int)param_1 + 0x210) = *(int *)((int)param_1 + 0x210) + 1;
C                     if ((int)local_254 < 0) goto LAB_6f84e550;
C                   }
C                   if (puStack_264 != (ushort *)0x3) goto LAB_6f84e4e3;
C                   goto LAB_6f84e4ed;
C                 }
C                 if ((uStack_24c & 0x20000) == 0) {
C                   iVar10 = iStack_238;
C                   if (iStack_238 == 0) {
C                     iVar10 = iStack_23c;
C                   }
C                   lstrcpyA(aCStack_1f8,(LPCSTR)puStack_268);
C                   iVar11 = lstrcmpiA(pCStack_26c,"FAX");
C                   if (iVar11 == 0) {
C                     FUN_6f852980(*(int *)((int)param_1 + 8),iVar10);
C                   }
C                   pcVar7 = (char *)FUN_6f84e5d0(*(int *)((int)param_1 + 8),
C                                                 *(undefined4 *)((int)param_1 + 0x1bc),local_270,
C                                                 *(char **)(piVar12[2] + 8),pcStack_220,pCStack_26c,
C                                                 aCStack_1f8,(undefined4 *)pCStack_244,
C                                                 (char)puStack_264,0x81,0,&local_258);
C                   if (-1 < (int)pcVar7) {
C                     if ((uStack_24c & 0x40000) != 0) {
C                       *local_258 = *local_258 | 1;
C                     }
C                     pcVar7 = (char *)FUN_6f851a10(param_1,(byte *)&local_258);
C joined_r0x6f84e3be:
C                     if (-1 < (int)pcVar7) goto LAB_6f84e3c4;
C                   }
C                   goto LAB_6f84e550;
C                 }
C                 uVar9 = *(uint *)(*(int *)((int)param_1 + 8) + 0x84);
C                 *(uint *)(*(int *)((int)param_1 + 8) + 0x84) = uVar9 & 0xefffffff;
C                 puStack_214 = puStack_264;
C                 uStack_210 = *(undefined4 *)(piVar12[2] + 8);
C                 pcVar7 = (char *)FUN_6f83fbb0(*(void **)((int)param_1 + 8),iStack_23c,uStack_240,
C                                               pCStack_244,(LPCSTR)puStack_268,&puStack_214);
C                 *(uint *)(*(int *)((int)param_1 + 8) + 0x84) = uVar9;
C                 if (pcVar7 != (char *)0x1) {
C                   if (pcVar7 == (char *)0x2) {
C                     pcVar7 = (char *)0x0;
C                     local_270 = 2;
C                   }
C                   goto joined_r0x6f84e3be;
C                 }
C                 (**(code **)(*(int *)((int)param_1 + 8) + 4))(piVar12[2]);
C                 (**(code **)(*(int *)((int)param_1 + 8) + 4))(puStack_264);
C LAB_6f84e4f8:
C                 local_260 = (int *)0x0;
C                 if (puStack_230 != (ushort *)0x0) {
C                   (**(code **)(*(int *)((int)param_1 + 8) + 4))(puStack_230);
C                   (**(code **)(*(int *)((int)param_1 + 8) + 4))(local_270);
C                 }
C                 goto LAB_6f84de28;
C               }
C             }
C           }
C         }
C       }
C     }
C LAB_6f84e550:
C     if (local_254 != (char *)0x0) {
C       pcVar7 = local_254;
C     }
C     if ((piVar12 != (int *)0x0) && (piVar12[2] != 0)) {
C       (**(code **)(*(int *)((int)param_1 + 8) + 4))(piVar12[2]);
C     }
C     (**(code **)(*(int *)((int)param_1 + 8) + 4))(local_260);
C     (**(code **)(*(int *)((int)param_1 + 8) + 4))(local_22c);
C     if (puStack_264 != (ushort *)0x0) {
C       (**(code **)(*(int *)puStack_264 + 8))(puStack_264);
C     }
C     piVar12 = *(int **)((int)param_1 + 0x20c);
C     if ((piVar12 != (int *)0x0) && (((int)pcVar7 < 0 || (*(int *)((int)param_1 + 0x1d8) == 0)))) {
C       (**(code **)(*piVar12 + 8))(piVar12);
C       *(undefined4 *)((int)param_1 + 0x20c) = 0;
C     }
C   }
C   return pcVar7;
C }
C 
