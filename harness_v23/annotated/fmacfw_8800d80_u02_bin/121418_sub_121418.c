// v23 annotated: sub_121418 @ 0x121418
// Original: 121418_sub_121418.c
// Primary struct: <unclustered>
//
// sub_121418 @ 0x121418, size 534 bytes
int __fastcall sub_121418(unsigned __int8 *a1)
{
  unsigned int v1; // r7
  int v2; // r5
  int v4; // r6
  _DWORD *v5; // r2
  unsigned __int16 *v6; // r7
  _DWORD *v7; // r3
  _BYTE *v8; // r3
  _DWORD *v9; // r3
  int v10; // r0
  int v11; // r1
  _DWORD *v12; // r3
  _DWORD *v13; // r2
  unsigned __int8 v15; // r6
  _DWORD *v16; // r2
  int v17; // r1
  _DWORD *v18; // r3
  _DWORD *v19; // r3
  _DWORD *v20; // r3
  _DWORD *v21; // r3
  _DWORD *v22; // r3
  int v23; // r5

  v1 = a1[1];
  v2 = a1[41];
  if ( v1 == 255 )
  {
    if ( a1[40] == 5 )
    {
      v23 = HIBYTE(*(_DWORD *)off_121668) - 3 + *a1 + 2 * v2;
      v4 = (unsigned __int8)v23;
      fmac_init_struct(a1, v23);
      return v4;
    }
    v15 = *a1;
    v16 = off_121640;
    v17 = dword_121660;
    *(_DWORD *)off_12163C = -1;
    *v16 = -1;
    v4 = (unsigned __int8)(v15 + 4 * v2);
    feature_guard_check(256, v17);
    fmac_init_struct(a1, v4);
  }
  else
  {
    if ( **(__int16 **)off_121630 < 0 && v1 > 0x23 )
      sub_12F46C(dword_121648, dword_121644, 1424);
    v4 = (unsigned __int8)(v1 + 16);
    feature_guard_check(256, dword_121634);
    sub_11F298((int)a1, v1 + 16);
    v5 = off_121640;
    v6 = (unsigned __int16 *)(dword_121638 + 696 * v1);
    *(_DWORD *)off_12163C = v6[19] | (v6[20] << 16);
    *v5 = v6[21];
  }
  switch ( a1[40] )
  {
    case 0u:
      v18 = off_12164C;
      *(_DWORD *)off_12164C = *((_DWORD *)a1 + 2);
      v18[1] = *((_DWORD *)a1 + 3);
      v18[2] = *((_DWORD *)a1 + 4);
      v18[3] = *((_DWORD *)a1 + 5);
      v10 = 256;
      v11 = 0;
      break;
    case 1u:
      v7 = off_12164C;
      *(_DWORD *)off_12164C = *((_DWORD *)a1 + 2);
      v7[1] = *((_DWORD *)a1 + 3);
      v7[2] = *((_DWORD *)a1 + 4);
      v8 = *(_BYTE **)off_121650;
      *(_DWORD *)off_121654 = *((_DWORD *)a1 + 5);
      if ( (*v8 & 1) != 0 )
      {
        v9 = off_121658;
        *(_DWORD *)off_121658 = *((_DWORD *)a1 + 6);
        v9[1] = *((_DWORD *)a1 + 7);
        v9[2] = *((_DWORD *)a1 + 8);
        v9[3] = *((_DWORD *)a1 + 9);
      }
      else
      {
        *(_DWORD *)off_121664 &= ~1u;
      }
      v10 = 512;
      v11 = 4096;
      break;
    case 2u:
      v12 = off_12164C;
      *(_DWORD *)off_12164C = *((_DWORD *)a1 + 2);
      v12[1] = *((_DWORD *)a1 + 3);
      v12[2] = *((_DWORD *)a1 + 4);
      v12[3] = *((_DWORD *)a1 + 5);
      v10 = 768;
      v11 = 0;
      break;
    case 3u:
      v10 = 256;
      v11 = 4096;
      goto LABEL_22;
    case 4u:
      v22 = off_12164C;
      *(_DWORD *)off_12164C = *((_DWORD *)a1 + 2);
      v22[1] = *((_DWORD *)a1 + 3);
      v22[2] = *((_DWORD *)a1 + 4);
      v22[3] = *((_DWORD *)a1 + 5);
      v10 = 1024;
      v11 = 4096;
      goto LABEL_20;
    case 6u:
      v10 = 1280;
      v11 = 0;
      goto LABEL_22;
    case 7u:
      v10 = 1280;
      goto LABEL_19;
    case 8u:
      v10 = 768;
LABEL_19:
      v19 = off_12164C;
      *(_DWORD *)off_12164C = *((_DWORD *)a1 + 2);
      v19[1] = *((_DWORD *)a1 + 3);
      v19[2] = *((_DWORD *)a1 + 4);
      v19[3] = *((_DWORD *)a1 + 5);
      v11 = 0x2000;
LABEL_20:
      v20 = off_121658;
      *(_DWORD *)off_121658 = *((_DWORD *)a1 + 6);
      v20[1] = *((_DWORD *)a1 + 7);
      v20[2] = *((_DWORD *)a1 + 8);
      v20[3] = *((_DWORD *)a1 + 9);
      break;
    default:
      if ( **(__int16 **)off_121630 < 0 )
        sub_12F46C(dword_121670, dword_12166C, 159);
      v10 = 0;
      v11 = 4096;
LABEL_22:
      v21 = off_12164C;
      *(_DWORD *)off_12164C = *((_DWORD *)a1 + 2);
      v21[1] = *((_DWORD *)a1 + 3);
      v21[2] = *((_DWORD *)a1 + 4);
      v21[3] = *((_DWORD *)a1 + 5);
      break;
  }
  v13 = off_12165C;
  *(_DWORD *)off_12165C = (16 * v2) | (4 * a1[42]) | v10 | (v4 << 16) | v11 | 0x40000000;
  while ( (*v13 & 0x40000000) != 0 )
    ;
  return v4;
}

