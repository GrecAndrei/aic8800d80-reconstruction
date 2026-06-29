// fwstruct annotate: 1359cc_sub_1359CC.c
// sub_1359CC @ 0x1359cc, size 148 bytes
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_1359CC(
        int a1,
        __int16 a2,
        int *a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11)
{
  int v11; // r4
  int v12; // r5
  int v13; // r7
  __int16 v14; // r8
  char v15; // r9
  int v16; // r12
  __int16 v17; // r1
  int v18; // r0
  __int16 v19; // r6
  int v20; // r4
  int v21; // r4
  int v22; // r3
  int v23; // r2
  int v24; // r1
  __int64 v25; // r2

  *(_WORD *)(a4 + 116) = *((_WORD *)a3 + 2);
  v17 = a2 + 1;
  v18 = *(_DWORD *)(v11 + 100);
  v19 = *(_WORD *)(v11 + 104);
  v20 = *a3;
  *(_DWORD *)(a4 + 118) = v18;
  LOWORD(v18) = *((_WORD *)a3 + 2);
  *(_BYTE *)(a4 + 109) = v15;
  *(_BYTE *)(a4 + 110) = v15;
  *(_BYTE *)(a4 + 111) = v15;
  *(_WORD *)(a4 + 122) = v19;
  *(_DWORD *)(a4 + 124) = v20;
  *(_WORD *)(a4 + 128) = v18;
  *(_WORD *)(v16 + 508) = v17;
  *(_WORD *)(a4 + 130) = 16 * v17;
  *(_BYTE *)(v13 + 28) = *(_BYTE *)(v12 + 8);
  *(_BYTE *)(v13 + 29) = *(_BYTE *)(v12 + 7);
  v21 = a4 + 108;
  *(_BYTE *)(v13 + 51) = v15;
  *(_BYTE *)(v13 + 53) = v15;
  sub_13C734(v13, 208, 8);
  sub_13B13C(v13, v21, 24);
  v22 = *(unsigned __int8 *)(v13 + 51) + 24;
  v23 = v22 + v21;
  *(_BYTE *)(v22 + v21) = 8;
  *(_BYTE *)(v23 + 1) = 1;
  v24 = *(_DWORD *)(v13 + 76);
  *(_WORD *)(v23 + 2) = v14;
  HIDWORD(v25) = v22 + *(unsigned __int8 *)(v13 + 53) + 4;
  LODWORD(v25) = *(_DWORD *)(v24 + 28) - 1 + HIDWORD(v25);
  HIDWORD(v25) += 4;
  *(_QWORD *)(v24 + 32) = v25;
  sub_1190B4(v13, 5);
  __asm { POP.W           {R4-R9,PC} }
}

