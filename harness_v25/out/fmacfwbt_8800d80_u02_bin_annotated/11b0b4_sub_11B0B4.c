// fwstruct annotate: 11b0b4_sub_11B0B4.c
// sub_11B0B4 @ 0x11b0b4, size 406 bytes
int __fastcall sub_11B0B4(int result)
{
  _DWORD *v1; // r5
  __int16 **v2; // r6
  _DWORD *v3; // r4
  int v4; // r3
  int v5; // r2
  int v6; // r7
  int *v7; // r4
  int v8; // r8
  int v9; // r3
  int *v10; // r6
  int v11; // r1
  unsigned int v12; // r3
  int v13; // r9
  int v14; // r4
  int v15; // r10
  int v16; // r3
  int v17; // r3
  int v18; // [sp+4h] [bp-4h] BYREF

  if ( result == 5 )
  {
    v1 = (_DWORD *)dword_11B264;
  }
  else
  {
    result *= 21;
    v1 = (_DWORD *)(dword_11B24C + 4 * result);
  }
  v2 = (__int16 **)off_11B250;
  v3 = (_DWORD *)v1[3];
  if ( **(__int16 **)off_11B250 < 0 && !v3 )
    result = sub_12F694(dword_11B260, dword_11B25C, 3166);
  while ( 1 )
  {
    v4 = v3[9];
    if ( (v4 & 0x200000) != 0 )
      break;
    if ( *(int *)(v3[19] + 72) < 0 )
    {
      v3 = (_DWORD *)*v3;
      if ( v3 )
        continue;
    }
    return result;
  }
  v5 = **v2;
  if ( v5 >= 0 )
  {
    v6 = v3[17];
    v7 = *(int **)(v6 + 4 * ((unsigned __int8)*(_DWORD *)off_11B254 + 82));
    v8 = v7[19];
LABEL_10:
    v9 = v7[9];
    goto LABEL_11;
  }
  if ( (v4 & 0x380000) == 0x280000 )
  {
    v6 = v3[17];
    v7 = *(int **)(v6 + 4 * ((unsigned __int8)*(_DWORD *)off_11B254 + 82));
    v8 = v7[19];
  }
  else
  {
    sub_12F694(dword_11B268, dword_11B25C, 3182);
    v6 = v3[17];
    v5 = **v2;
    v7 = *(int **)(v6 + 4 * ((unsigned __int8)*(_DWORD *)off_11B254 + 82));
    v8 = v7[19];
    if ( v5 >= 0 )
      goto LABEL_10;
  }
  v9 = v7[9];
  if ( (v9 & 0x380000) == 0x380000 )
  {
    sub_12F694(dword_11B26C, dword_11B25C, 3192);
    v9 = v7[9];
  }
  v5 = **v2;
LABEL_11:
  v10 = (int *)off_11B258;
  v11 = *(_DWORD *)off_11B258;
  v7[9] = v9 | 0x380000;
  v12 = v9 & 0xFFC7FEFF | 0x380100;
  if ( *(_BYTE *)(v11 + 1) )
  {
    v15 = v6 + 84;
    v13 = *(_DWORD *)(v6 + 88);
    v14 = *v7;
    *(_DWORD *)(v8 + 68) = v12;
    *(_DWORD *)(v8 + 20) = v6 + 84;
    if ( v5 >= 0 )
      goto LABEL_13;
  }
  else
  {
    v13 = *(_DWORD *)(v6 + 20);
    v14 = *v7;
    *(_DWORD *)(v8 + 68) = v12;
    *(_DWORD *)(v8 + 20) = 0;
    v15 = v6 + 16;
    if ( v5 >= 0 )
      goto LABEL_13;
  }
  if ( !v14 )
    sub_12F694(dword_11B260, dword_11B25C, 3217);
LABEL_13:
  result = rf_cmd_process_n_4c5(v14, (int)&v18);
  if ( !result )
    return result;
  v16 = *v10;
  *(_DWORD *)(v15 + 4) = result;
  if ( *(_BYTE *)(v16 + 1) )
  {
    v17 = v18;
    *(_DWORD *)(v18 + 4) = v13;
    if ( v13 )
      return result;
    *v1 = v17;
  }
  else if ( (*(_DWORD *)(v18 + 56) & 0x200000) != 0 )
  {
    *(_DWORD *)(result + 4) = v13;
    if ( v13 )
      return result;
  }
  else
  {
    *(_DWORD *)(v18 + 4) = v13;
    if ( v13 )
      return result;
  }
  if ( (*(_DWORD *)(result + 56) & 0x200000) != 0 )
  {
    v1[1] = result;
    v1[2] = 1;
  }
  else
  {
    v1[1] = 0;
    v1[2] = 0;
  }
  return result;
}

