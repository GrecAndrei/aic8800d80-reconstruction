// fwstruct annotate: 11dc04_sub_11DC04.c
// sub_11DC04 @ 0x11dc04, size 266 bytes
_DWORD *__fastcall sub_11DC04(_DWORD *a1, int a2, _WORD *a3)
{
  int *v3; // r7
  int v4; // r10
  _DWORD *v5; // r6
  __int16 **v6; // r11
  _DWORD *v7; // r8
  int v9; // r9
  int v10; // r5
  int v11; // r0
  int v12; // r3
  _DWORD *v13; // r4
  int v14; // r2
  int v15; // r0
  int v16; // r1
  _DWORD *v17; // r3
  __int16 v18; // r5
  __int16 v19; // r2
  int v20; // r1
  int v22; // [sp+8h] [bp-14h]
  int v23; // [sp+8h] [bp-14h]
  __int16 v24; // [sp+8h] [bp-14h]
  _DWORD *v25; // [sp+Ch] [bp-10h]

  v3 = (int *)off_11DD10;
  v4 = (unsigned __int16)*a3;
  v5 = (_DWORD *)*a1;
  v6 = (__int16 **)off_11DD20;
  v7 = nullptr;
  *((_BYTE *)off_11DD10 + 32) = 1;
  v9 = 0;
  v25 = nullptr;
  while ( 1 )
  {
    v18 = *((_WORD *)v5 + 4);
    v19 = v5[3] + 1;
    v20 = (unsigned __int16)(v19 - v18);
    if ( a2 + v4 >= v20 )
      break;
    v23 = a2;
    v11 = sub_11017C();
    v10 = 0;
    v12 = v23;
    v9 = 1;
    v13 = (_DWORD *)v11;
    if ( !v11 )
      goto LABEL_15;
LABEL_5:
    v14 = v3[1];
    if ( !v14 )
      *v3 = v11;
    v15 = **v6;
    v3[3] += v12;
    v3[1] = v14 + 1;
    v16 = v5[2];
    if ( v15 < 0 && !v16 )
    {
      v24 = v12;
      sub_12F32C(dword_11DD18, dword_11DD14, 683);
      v16 = v5[2];
      LOWORD(v12) = v24;
    }
    sub_110FFC(v13, v16, 0, v12, v9);
    if ( v7 )
      v7[1] = v13;
    v3[2] = (int)v13;
    if ( !v10 )
      goto LABEL_16;
    v17 = (_DWORD *)v5[1];
    if ( **v6 < 0 && !v17 )
    {
      sub_12F32C(dword_11DD1C, dword_11DD14, 704);
      v17 = nullptr;
    }
    v25 = v5;
    v7 = v13;
    v5 = v17;
    a2 = v10;
  }
  v10 = (unsigned __int16)(v18 + a2 + v4 - v19);
  v22 = (unsigned __int16)(v20 - v4);
  if ( !v10 )
    v9 = 1;
  v11 = sub_11017C();
  v4 = 0;
  v12 = v22;
  v13 = (_DWORD *)v11;
  if ( v11 )
    goto LABEL_5;
LABEL_15:
  *((_BYTE *)v3 + 32) = v11;
LABEL_16:
  *a1 = v5;
  *a3 = v4;
  return v25;
}

