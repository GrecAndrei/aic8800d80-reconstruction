// sub_11C07C @ 0x11c07c, size 560 bytes
int __fastcall sub_11C07C(int result)
{
  _DWORD *v1; // r2
  __int16 *v2; // r1
  unsigned int v3; // r3
  int v4; // r5
  int v5; // r1
  __int16 v6; // r0
  int v7; // r1
  int v8; // r3
  int v9; // r4
  int v10; // r5
  int v11; // r6
  unsigned int v12; // r5
  int v13; // r8
  int v14; // r9
  int v15; // lr
  bool v16; // nf
  int v17; // r0
  unsigned int v18; // r6
  int v19; // r12
  int v20; // r5
  unsigned int v21; // r4
  __int16 v22; // r9
  unsigned int *v23; // r10
  unsigned int v24; // r11
  __int16 v25; // r8
  int v26; // r1
  __int16 v27; // r7
  _WORD *v28; // r3
  int v29; // r1
  int v30; // r0
  int v31; // r2
  int v32; // r11
  char v33; // r7
  unsigned int v34; // r4
  __int16 v35; // [sp+0h] [bp-Ch]
  __int16 v36; // [sp+4h] [bp-8h]

  v1 = off_11C2B0;
  v2 = *(__int16 **)off_11C2AC;
  v3 = *(_DWORD *)(result + 84);
  v4 = *(_DWORD *)(result + 28);
  *((_BYTE *)off_11C2B0 + 200) = 0;
  v5 = *v2;
  if ( v5 < 0 )
  {
    result = *(unsigned __int16 *)(result + 48);
    if ( (unsigned int)result <= 0x1C )
    {
      v29 = dword_11C2D8;
      v30 = dword_11C2E0;
      v31 = 2509;
      return sub_12F408(v30, v29, v31, v3);
    }
  }
  if ( (v3 & 0x2000000) == 0 )
    goto LABEL_18;
  v6 = v3 >> 15;
  v3 = (v3 >> 15) & 0x3FF;
  if ( v5 < 0 && (v6 & 0x3F0) == 0 )
  {
    v29 = dword_11C2D8;
    v30 = dword_11C2DC;
    v31 = 2522;
    return sub_12F408(v30, v29, v31, v3);
  }
  v7 = dword_11C2B4;
  v8 = (unsigned __int8)(v3 - 16);
  v9 = dword_11C2B4 + 696 * v8;
  result = *(unsigned __int8 *)(v9 + 37);
  if ( *(_BYTE *)(v9 + 37) )
  {
    v10 = *(unsigned __int8 *)(v9 + 34);
    v1[45] = *(_DWORD *)(v9 + 38);
    v11 = dword_11C2BC;
    *((_WORD *)off_11C2B8 + 2) = *(_WORD *)(v9 + 42);
    result = v1[4];
    if ( result == v11 + 1320 * v10 )
    {
      result = *(_DWORD *)off_11C2C4 & 0x3F;
      if ( *(unsigned __int8 *)(*(_DWORD *)off_11C2C0 + 62) + 3 < result )
      {
        v12 = *(_DWORD *)off_11C2CC;
        v13 = v1[42];
        v14 = *(_DWORD *)off_11C2C8 & 0xF;
        v15 = HIWORD(*(_DWORD *)off_11C2C8) & 3;
        v16 = (*(_DWORD *)off_11C2C8 & 0x80000) != 0;
        v35 = (unsigned __int16)*(_DWORD *)off_11C2C8 >> 4;
        *((_WORD *)v1 + 94) = v35;
        *((_BYTE *)v1 + 191) = v14;
        *((_BYTE *)v1 + 195) = v15;
        v17 = (unsigned __int8)v12 >> 4;
        v18 = v12 & 7;
        if ( v16 )
        {
          v32 = 2;
          v33 = 2;
          v36 = 1024;
        }
        else
        {
          v32 = 1;
          v33 = 1;
          v36 = 512;
        }
        v19 = (v12 >> 9) & 7;
        *((_BYTE *)v1 + 192) = v33;
        *((_BYTE *)v1 + 193) = v17;
        *((_BYTE *)v1 + 199) = (v12 & 0x1000) != 0;
        *((_BYTE *)v1 + 194) = v19;
        *((_BYTE *)v1 + 196) = v18;
        if ( v14 )
        {
          LOBYTE(v20) = *((_BYTE *)v1 + 198);
        }
        else
        {
          v34 = v12 >> 30;
          v20 = HIBYTE(v12) & 3;
          *((_BYTE *)v1 + 197) = *(_BYTE *)(dword_11C2EC + v34);
          *((_BYTE *)v1 + 198) = v20;
        }
        while ( *(int *)off_11C2E4 >= 0 )
          ;
        v21 = *(_DWORD *)off_11C2E4 & dword_11C2D0;
        if ( v18 > 2 )
          v22 = *(unsigned __int16 *)(dword_11C2F0 + 2 * (3 * ((unsigned __int8)(v18 - 3) >> 1) + v32 + 6 * v17)) << ((v18 - 3) & 1);
        else
          v22 = *(_WORD *)(*(_DWORD *)(dword_11C2D4 + 4 * v18) + 2 * (3 * v17 + v32));
        v23 = (unsigned int *)off_11C2E8;
        if ( v21 >= *(_DWORD *)(v13 + 12) )
          v21 = *(_DWORD *)(v13 + 12);
        v1[44] = v21;
        v24 = *v23;
        v25 = *(unsigned __int8 *)(v13 + 28);
        v26 = v7 + 696 * v8;
        v27 = v36 | v17;
        result = *(_DWORD *)(v26 + 340);
        v1[42] = v26;
        *((_BYTE *)v1 + 200) = v21 > 0x27;
        *((_WORD *)v1 + 93) = v25 * (1 << v20) * v22;
        v1[43] = (HIBYTE(v24) << 6) | 0x13;
        *(_WORD *)(result + 130) = v27 | ((_WORD)v15 << 7) | (16 * v19) | 0x3000;
        *(_WORD *)(result + 132) = v18 | (8 * v35);
        v1[51] = 0;
      }
    }
  }
  else
  {
LABEL_18:
    v28 = *(_WORD **)(v4 + 8);
    *((_WORD *)v1 + 90) = v28[5];
    *((_WORD *)v1 + 91) = v28[6];
    *((_WORD *)v1 + 92) = v28[7];
  }
  return result;
}

