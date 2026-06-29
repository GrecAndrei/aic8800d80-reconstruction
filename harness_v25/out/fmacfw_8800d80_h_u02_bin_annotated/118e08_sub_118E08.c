// fwstruct annotate: 118e08_sub_118E08.c
// sub_118E08 @ 0x118e08, size 304 bytes
int __fastcall sub_118E08(int a1, __int16 a2, int a3, int a4)
{
  int v4; // r11
  int v5; // r4
  int v7; // r7
  int v9; // r0
  int v12; // r2
  int v13; // r5
  int v14; // r7
  int v15; // r3
  int v16; // r4
  int v17; // r1
  int v18; // r12
  __int16 v19; // lr
  int v20; // r0
  __int16 v21; // r2
  char v22; // r3

  v4 = dword_118F48;
  v5 = dword_118F38;
  v7 = *(unsigned __int8 *)(dword_118F48 + 696 * a1 + 34);
  v9 = *(_DWORD *)(dword_118F38 + 1320 * v7 + 72);
  if ( !v9 )
  {
    if ( **(__int16 **)off_118F3C >= 0 )
    {
LABEL_10:
      v13 = sub_118B04(1, 26);
      if ( !v13 )
        return 1;
      goto LABEL_4;
    }
LABEL_9:
    sub_12F32C(dword_118F44, dword_118F40, 520);
    goto LABEL_10;
  }
  v12 = *(unsigned __int8 *)(v9 + 4);
  if ( **(__int16 **)off_118F3C < 0 && v12 == 2 )
    goto LABEL_9;
  v13 = sub_118B04((*(unsigned __int8 *)(dword_118F38 + 1320 * v7 + 1224) | v12) != 0, 26);
  if ( !v13 )
    return 1;
LABEL_4:
  v14 = v5 + 1320 * v7;
  sub_12C3A8(v14, v13);
  v15 = v4 + 696 * a1;
  v16 = *(_DWORD *)(v13 + 72);
  v17 = *(_DWORD *)(v15 + 38);
  v18 = *(unsigned __int8 *)(v14 + 106);
  v19 = *(_WORD *)(v15 + 42);
  v20 = *(_DWORD *)(v14 + 100);
  v21 = *(_WORD *)(v14 + 104);
  *(_WORD *)(v16 + 122) = v21;
  *(_WORD *)(v16 + 116) = v19;
  *(_DWORD *)(v16 + 112) = v17;
  *(_DWORD *)(v16 + 118) = v20;
  *(_BYTE *)(v16 + 110) = 0;
  *(_BYTE *)(v16 + 111) = 0;
  if ( v18 )
  {
    *(_DWORD *)(v16 + 124) = *(_DWORD *)(v14 + 100);
    *(_WORD *)(v16 + 128) = v21;
    *(_BYTE *)(v16 + 108) = -56;
    *(_BYTE *)(v16 + 109) = 2;
  }
  else
  {
    *(_DWORD *)(v16 + 124) = v17;
    *(_WORD *)(v16 + 128) = v19;
    *(_BYTE *)(v16 + 108) = -56;
    *(_BYTE *)(v16 + 109) = 1;
  }
  v22 = *(_BYTE *)(v4 + 696 * a1 + 34);
  *(_WORD *)(v16 + 132) = a2;
  *(_BYTE *)(v16 + 130) = 0;
  *(_BYTE *)(v16 + 131) = 0;
  *(_DWORD *)(v13 + 88) = a3;
  *(_DWORD *)(v13 + 92) = a4;
  *(_BYTE *)(v13 + 28) = v22;
  *(_BYTE *)(v13 + 29) = a1;
  sub_118B34(v13, 5);
  return 0;
}

