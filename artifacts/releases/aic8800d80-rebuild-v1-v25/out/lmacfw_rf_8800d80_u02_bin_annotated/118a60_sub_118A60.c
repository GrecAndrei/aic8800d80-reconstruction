// fwstruct annotate: 118a60_sub_118A60.c
// sub_118A60 @ 0x118a60, size 496 bytes
// Doc: sub_1218A60 [scan]: Scans structure fields (byte at +1, byte at +0x29) and branches on 0xff sentinel
// sub_1218A60 [scan]: Scans structure fields (byte at +1, byte at +0x29) and branches on 0xff sentinel
int __fastcall sub_118A60(char *a1)
{
  unsigned int v1; // r7
  int v2; // r5
  int v4; // r1
  _DWORD *v5; // r3
  int v6; // r2
  int v7; // r6
  _DWORD *v8; // r3
  _BYTE *v9; // r3
  _DWORD *v10; // r3
  int v11; // r0
  int v12; // r1
  _DWORD *v13; // r3
  _DWORD *v14; // r2
  _DWORD *v16; // r2
  char v17; // r6
  int v18; // r1
  _DWORD *v19; // r3
  _DWORD *v20; // r3
  _DWORD *v21; // r3
  _DWORD *v22; // r3
  _DWORD *v23; // r3
  int v24; // [sp+0h] [bp-14h] BYREF
  __int16 v25; // [sp+4h] [bp-10h]
  int v26; // [sp+8h] [bp-Ch] BYREF
  unsigned __int16 v27; // [sp+Ch] [bp-8h]

  v1 = (unsigned __int8)a1[1];
  v2 = (unsigned __int8)a1[41];
  if ( v1 == 255 )
  {
    v16 = off_118C60;
    v17 = *a1;
    v18 = dword_118C80;
    *(_DWORD *)off_118C5C = -1;
    *v16 = -1;
    v7 = (unsigned __int8)(v17 + 4 * v2);
    sub_11F74C(256, v18, (unsigned __int8)a1[41], (unsigned __int8)a1[40]);
  }
  else
  {
    if ( **(__int16 **)off_118C50 < 0 && v1 > 3 )
      rf_cmd_send_n264(dword_118C68, dword_118C64, 1424);
    sub_11F74C(256, dword_118C54, v1, (unsigned __int8)a1[40]);
    v4 = *(_DWORD *)(dword_118C58 + 4);
    v24 = *(_DWORD *)dword_118C58;
    v25 = v4;
    sub_1282E8(&v26, &v24, 6);
    v5 = off_118C60;
    v6 = v27;
    *(_DWORD *)off_118C5C = v26;
    v7 = (unsigned __int8)(v1 + 16);
    *v5 = v6;
  }
  switch ( a1[40] )
  {
    case 0:
      v19 = off_118C6C;
      *(_DWORD *)off_118C6C = *((_DWORD *)a1 + 2);
      v19[1] = *((_DWORD *)a1 + 3);
      v19[2] = *((_DWORD *)a1 + 4);
      v19[3] = *((_DWORD *)a1 + 5);
      v11 = 256;
      v12 = 0;
      break;
    case 1:
      v8 = off_118C6C;
      *(_DWORD *)off_118C6C = *((_DWORD *)a1 + 2);
      v8[1] = *((_DWORD *)a1 + 3);
      v8[2] = *((_DWORD *)a1 + 4);
      v9 = *(_BYTE **)off_118C70;
      *(_DWORD *)off_118C74 = *((_DWORD *)a1 + 5);
      if ( (*v9 & 1) != 0 )
      {
        v10 = off_118C78;
        *(_DWORD *)off_118C78 = *((_DWORD *)a1 + 6);
        v10[1] = *((_DWORD *)a1 + 7);
        v10[2] = *((_DWORD *)a1 + 8);
        v10[3] = *((_DWORD *)a1 + 9);
      }
      else
      {
        *(_DWORD *)off_118C84 &= ~1u;
      }
      v11 = 512;
      v12 = 4096;
      break;
    case 2:
      v13 = off_118C6C;
      *(_DWORD *)off_118C6C = *((_DWORD *)a1 + 2);
      v13[1] = *((_DWORD *)a1 + 3);
      v13[2] = *((_DWORD *)a1 + 4);
      v13[3] = *((_DWORD *)a1 + 5);
      v11 = 768;
      v12 = 0;
      break;
    case 3:
      v11 = 256;
      v12 = 4096;
      goto LABEL_21;
    case 4:
      v23 = off_118C6C;
      *(_DWORD *)off_118C6C = *((_DWORD *)a1 + 2);
      v23[1] = *((_DWORD *)a1 + 3);
      v23[2] = *((_DWORD *)a1 + 4);
      v23[3] = *((_DWORD *)a1 + 5);
      v11 = 1024;
      v12 = 4096;
      goto LABEL_19;
    case 6:
      v11 = 1280;
      v12 = 0;
      goto LABEL_21;
    case 7:
      v11 = 1280;
      goto LABEL_18;
    case 8:
      v11 = 768;
LABEL_18:
      v20 = off_118C6C;
      *(_DWORD *)off_118C6C = *((_DWORD *)a1 + 2);
      v20[1] = *((_DWORD *)a1 + 3);
      v20[2] = *((_DWORD *)a1 + 4);
      v20[3] = *((_DWORD *)a1 + 5);
      v12 = 0x2000;
LABEL_19:
      v21 = off_118C78;
      *(_DWORD *)off_118C78 = *((_DWORD *)a1 + 6);
      v21[1] = *((_DWORD *)a1 + 7);
      v21[2] = *((_DWORD *)a1 + 8);
      v21[3] = *((_DWORD *)a1 + 9);
      break;
    default:
      if ( **(__int16 **)off_118C50 < 0 )
        rf_cmd_send_n264(dword_118C8C, dword_118C88, 159);
      v11 = 0;
      v12 = 4096;
LABEL_21:
      v22 = off_118C6C;
      *(_DWORD *)off_118C6C = *((_DWORD *)a1 + 2);
      v22[1] = *((_DWORD *)a1 + 3);
      v22[2] = *((_DWORD *)a1 + 4);
      v22[3] = *((_DWORD *)a1 + 5);
      break;
  }
  v14 = off_118C7C;
  *(_DWORD *)off_118C7C = (16 * v2) | (4 * (unsigned __int8)a1[42]) | v11 | (v7 << 16) | v12 | 0x40000000;
  while ( (*v14 & 0x40000000) != 0 )
    ;
  return v7;
}

