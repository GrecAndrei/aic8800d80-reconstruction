// sub_1212D8 @ 0x1212d8, size 534 bytes
int __fastcall sub_1212D8(unsigned __int8 *a1)
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

  v1 = *(_DWORD *)(a1 + 0x4);
  v2 = *(_DWORD *)(a1 + 0xa4);
  if ( v1 == 255 )
  {
    if ( *(_DWORD *)(a1 + 0xa0) == 5 )
    {
      v23 = HIBYTE(*(_DWORD *)off_121528) - 3 + *a1 + 2 * v2;
      v4 = (unsigned __int8)v23;
      sub_11FEF8(a1, v23);
      return v4;
    }
    v15 = *a1;
    v16 = off_121500;
    v17 = dword_121520;
    *(_DWORD *)off_1214FC = -1;
    *v16 = -1;
    v4 = (unsigned __int8)(v15 + 4 * v2);
    sub_12EB90(256, v17);
    sub_11FEF8(a1, v4);
  }
  else
  {
    if ( **(__int16 **)off_1214F0 < 0 && v1 > 0x23 )
      sub_12F32C(dword_121508, dword_121504, 1424);
    v4 = (unsigned __int8)(v1 + 16);
    sub_12EB90(256, dword_1214F4);
    sub_11F158((int)a1, v1 + 16);
    v5 = off_121500;
    v6 = (unsigned __int16 *)(dword_1214F8 + 696 * v1);
    *(_DWORD *)off_1214FC = *(_DWORD *)(v6 + 0x4c) | (*(_DWORD *)(v6 + 0x50) << 16);
    *v5 = *(_DWORD *)(v6 + 0x54);
  }
  switch ( *(_DWORD *)(a1 + 0xa0) )
  {
    case 0u:
      v18 = off_12150C;
      *(_DWORD *)off_12150C = *((_DWORD *)a1 + 2);
      *(_DWORD *)(v18 + 0x4) = *((_DWORD *)a1 + 3);
      *(_DWORD *)(v18 + 0x8) = *((_DWORD *)a1 + 4);
      *(_DWORD *)(v18 + 0xc) = *((_DWORD *)a1 + 5);
      v10 = 256;
      v11 = 0;
      break;
    case 1u:
      v7 = off_12150C;
      *(_DWORD *)off_12150C = *((_DWORD *)a1 + 2);
      *(_DWORD *)(v7 + 0x4) = *((_DWORD *)a1 + 3);
      *(_DWORD *)(v7 + 0x8) = *((_DWORD *)a1 + 4);
      v8 = *(_BYTE **)off_121510;
      *(_DWORD *)off_121514 = *((_DWORD *)a1 + 5);
      if ( (*v8 & 1) != 0 )
      {
        v9 = off_121518;
        *(_DWORD *)off_121518 = *((_DWORD *)a1 + 6);
        *(_DWORD *)(v9 + 0x4) = *((_DWORD *)a1 + 7);
        *(_DWORD *)(v9 + 0x8) = *((_DWORD *)a1 + 8);
        *(_DWORD *)(v9 + 0xc) = *((_DWORD *)a1 + 9);
      }
      else
      {
        *(_DWORD *)off_121524 &= ~1u;
      }
      v10 = 512;
      v11 = 4096;
      break;
    case 2u:
      v12 = off_12150C;
      *(_DWORD *)off_12150C = *((_DWORD *)a1 + 2);
      *(_DWORD *)(v12 + 0x4) = *((_DWORD *)a1 + 3);
      *(_DWORD *)(v12 + 0x8) = *((_DWORD *)a1 + 4);
      *(_DWORD *)(v12 + 0xc) = *((_DWORD *)a1 + 5);
      v10 = 768;
      v11 = 0;
      break;
    case 3u:
      v10 = 256;
      v11 = 4096;
      goto LABEL_22;
    case 4u:
      v22 = off_12150C;
      *(_DWORD *)off_12150C = *((_DWORD *)a1 + 2);
      *(_DWORD *)(v22 + 0x4) = *((_DWORD *)a1 + 3);
      *(_DWORD *)(v22 + 0x8) = *((_DWORD *)a1 + 4);
      *(_DWORD *)(v22 + 0xc) = *((_DWORD *)a1 + 5);
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
      v19 = off_12150C;
      *(_DWORD *)off_12150C = *((_DWORD *)a1 + 2);
      *(_DWORD *)(v19 + 0x4) = *((_DWORD *)a1 + 3);
      *(_DWORD *)(v19 + 0x8) = *((_DWORD *)a1 + 4);
      *(_DWORD *)(v19 + 0xc) = *((_DWORD *)a1 + 5);
      v11 = 0x2000;
LABEL_20:
      v20 = off_121518;
      *(_DWORD *)off_121518 = *((_DWORD *)a1 + 6);
      *(_DWORD *)(v20 + 0x4) = *((_DWORD *)a1 + 7);
      *(_DWORD *)(v20 + 0x8) = *((_DWORD *)a1 + 8);
      *(_DWORD *)(v20 + 0xc) = *((_DWORD *)a1 + 9);
      break;
    default:
      if ( **(__int16 **)off_1214F0 < 0 )
        sub_12F32C(dword_121530, dword_12152C, 159);
      v10 = 0;
      v11 = 4096;
LABEL_22:
      v21 = off_12150C;
      *(_DWORD *)off_12150C = *((_DWORD *)a1 + 2);
      *(_DWORD *)(v21 + 0x4) = *((_DWORD *)a1 + 3);
      *(_DWORD *)(v21 + 0x8) = *((_DWORD *)a1 + 4);
      *(_DWORD *)(v21 + 0xc) = *((_DWORD *)a1 + 5);
      break;
  }
  v13 = off_12151C;
  *(_DWORD *)off_12151C = (16 * v2) | (4 * *(_DWORD *)(a1 + 0xa8)) | v10 | (v4 << 16) | v11 | 0x40000000;
  while ( (*v13 & 0x40000000) != 0 )
    ;
  return v4;
}

