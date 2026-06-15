// sub_11B578 @ 0x11b578, size 562 bytes
int __fastcall sub_11B578(int a1)
{
  _DWORD *v1; // r8
  char *v2; // r6
  int v3; // r2
  int v5; // r3
  __int16 v6; // r4
  int v7; // r0
  unsigned int v8; // r1
  int v9; // r0
  int v10; // r4
  unsigned int v11; // r0
  int v12; // r5
  char *v13; // r1
  int v14; // r6
  unsigned int *v15; // r12
  char *v16; // r2
  char *v17; // r9
  int v18; // lr
  __int16 v19; // r3
  unsigned int v20; // r3
  unsigned int v21; // t1
  int v22; // r2
  int v23; // r0
  __int16 v24; // r2
  _DWORD *v25; // r4
  _DWORD *v26; // r3
  int result; // r0
  int v28; // r3
  int v29; // r2
  _DWORD *v30; // r0
  _DWORD *v31; // r4
  int v32; // r2
  _DWORD *v33; // r1
  int v34; // r4
  __int16 v35; // r0
  unsigned int v36; // [sp+4h] [bp-8h]

  v1 = off_11B7C4;
  v2 = (char *)off_11B7AC;
  v3 = *((_DWORD *)off_11B7C4 + 4);
  v5 = *(_DWORD *)a1 + 38;
  *((_DWORD *)off_11B7AC + 18) = *(_DWORD *)v5;
  v6 = *(_WORD *)(v5 + 4);
  v7 = *(_DWORD *)(v3 + 100);
  v8 = *(unsigned __int16 *)(a1 + 18);
  LOWORD(v3) = *(_WORD *)(v3 + 104);
  *(_DWORD *)(v2 + 78) = v7;
  v9 = *(_DWORD *)v5;
  LOWORD(v5) = *(_WORD *)(v5 + 4);
  *((_WORD *)v2 + 38) = v6;
  v10 = 0;
  *((_DWORD *)v2 + 21) = v9;
  *((_WORD *)v2 + 41) = v3;
  *((_WORD *)v2 + 44) = v5;
  *((_DWORD *)v2 + 275) = 0;
  *((_DWORD *)v2 + 276) = 0;
  *((_DWORD *)v2 + 6) = 0;
  v11 = sub_119D2C((int)(v2 + 92), v8);
  v12 = *((_DWORD *)v2 + 6);
  v13 = v2;
  v14 = (unsigned __int16)(((*((_WORD *)v2 + 58) + 3) & 0xFFFC) + 4 + 4 * v11);
  v15 = (unsigned int *)(36 * *(unsigned __int8 *)(*(_DWORD *)a1 + 35) + 8248 + dword_11B7B0);
  v36 = v11 << 9;
  v16 = v13 + 92;
  v17 = v13;
  v18 = 2621440;
  while ( 1 )
  {
    v21 = *v15++;
    v20 = v21;
    if ( v21 )
      break;
LABEL_4:
    ++v10;
    v16 += 92;
    if ( v10 == 9 )
      goto LABEL_12;
  }
  if ( (unsigned int)(v14 + v12) <= *(_DWORD *)(a1 + 8) )
  {
    if ( v20 <= 0x3F0 )
    {
      v19 = ((unsigned __int16)((v20 + 15) >> 4) << 7) | 0x30;
    }
    else if ( v20 <= 0x400 )
    {
      v19 = 8240;
    }
    else if ( v20 > 0x4300 )
    {
      if ( v20 > 0x4400 )
      {
        if ( v20 <= 0x23C00 )
        {
          v19 = ((unsigned __int8)((v20 - 15361) >> 11) << 7) | 0x4030;
        }
        else if ( v20 <= 0x24400 )
        {
          v19 = 24624;
        }
        else if ( v20 > dword_11B7C0 )
        {
          v35 = 32560;
          if ( v20 == -1 )
            v35 = 32688;
          v19 = v35;
        }
        else
        {
          v19 = ((unsigned __int8)((v20 - 115713) >> 15) << 7) | 0x6030;
        }
      }
      else
      {
        v19 = 16432;
      }
    }
    else
    {
      v19 = ((unsigned __int8)((v20 - 1009) >> 4) << 7) | 0x2030;
    }
    *((_DWORD *)v16 + 9) = 0;
    *((_DWORD *)v16 + 14) = v36 | v18;
    *((_DWORD *)v16 + 15) = 0;
    *((_WORD *)v16 + 44) = v19 | v10;
    *((_DWORD *)v17 + 2) = v16;
    v12 = *((_DWORD *)v13 + 6) + v14;
    *((_DWORD *)v13 + 6) = v12;
    v17 = v16;
    v18 = 3145728;
    goto LABEL_4;
  }
LABEL_12:
  v1[52] |= 2u;
  if ( v12 )
  {
    v22 = *((_DWORD *)v17 + 14);
    *((_DWORD *)v17 + 2) = 0;
    if ( (v22 & 0x380000) == 0x280000 )
    {
      v32 = *((_DWORD *)v17 + 15);
      result = (int)off_11B7B4;
      v33 = off_11B7B8;
      v34 = dword_11B7BC;
      *((_DWORD *)v17 + 1) = 0;
      *((_BYTE *)v1 + 200) = 0;
      *((_DWORD *)v17 + 15) = v32 & 0xFF00;
      *((_DWORD *)v17 + 14) = 256;
      *((_DWORD *)v17 + 9) = v34;
      *(_DWORD *)result = v17;
      *v33 = 0x2000;
    }
    else
    {
      *((_DWORD *)v17 + 14) = v22 | 0x380000;
      v23 = *((_DWORD *)v13 + 14);
      v24 = *((_DWORD *)v13 + 15);
      *((_DWORD *)v13 + 1) = 0;
      *((_BYTE *)v1 + 200) = 0;
      v25 = off_11B7B4;
      v26 = off_11B7B8;
      *((_DWORD *)v13 + 14) = v23 | 0x100;
      *((_DWORD *)v13 + 15) = v24 & 0xFF00;
      *v25 = v13;
      *v26 = 0x2000;
      return 0x2000;
    }
  }
  else
  {
    v28 = *((_DWORD *)v13 + 38);
    v29 = dword_11B7BC;
    v30 = off_11B7B4;
    v31 = off_11B7B8;
    *((_DWORD *)v13 + 25) = 0;
    *((_DWORD *)v13 + 38) = v28 & 0xFF00;
    *((_DWORD *)v13 + 24) = 0;
    *((_BYTE *)v1 + 200) = 0;
    *v30 = v29 - 996;
    *v31 = 0x2000;
    *((_WORD *)v13 + 90) = 48;
    *((_DWORD *)v13 + 37) = 256;
    *((_DWORD *)v13 + 32) = v29;
    return 48;
  }
  return result;
}

