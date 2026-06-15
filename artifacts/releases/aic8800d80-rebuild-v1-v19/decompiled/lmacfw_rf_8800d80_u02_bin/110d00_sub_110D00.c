// sub_110D00 @ 0x110d00, size 1068 bytes
// Doc: rf_bus_reset2 [rf]: Reset the RF bus DMA chain (instance 2) by clearing descriptors, reprogramming the control word from RF register 0x1812, and re-arming the DMA engine at 0x40240018.
// rf_bus_reset2 [rf]: Reset the RF bus DMA chain (instance 2) by clearing descriptors, reprogramming the control word from RF register 0x1812, and re-arming the DMA engine at 0x40240018.
int sub_110D00()
{
  int v0; // r4
  int v1; // r1
  int v2; // r1
  _BYTE *v3; // r6
  unsigned int v4; // r1
  int v5; // r5
  unsigned int v6; // r2
  char *v7; // r3
  _DWORD *v8; // r7
  _DWORD *v9; // r0
  int v10; // r3
  char *v11; // r1
  _DWORD *v12; // r0
  _BYTE *v13; // r5
  unsigned int v14; // r1
  int result; // r0
  _BYTE *v16; // r0
  unsigned int v17; // r1
  _DWORD *v18; // r3
  _DWORD *v19; // r0
  unsigned int v20; // r2
  _DWORD *v21; // r3
  unsigned int v22; // r3
  _DWORD *v23; // r7
  unsigned int v24; // r3
  char *v25; // r2
  _DWORD *v26; // r5
  int v27; // r6
  int v28; // r7
  unsigned int v29; // r3
  char *v30; // r2
  int v31; // r0
  int v32; // r5
  int v33; // r0
  int v34; // r1
  int v35; // r0
  int v36; // r1
  unsigned int *v37; // r2
  int v38; // r5
  int v39; // r1
  unsigned int v40; // r3
  int v41; // r1
  _BYTE *v42; // r6
  void *v43; // r3
  int v44; // r1
  void *v45; // r3
  int v46; // r1
  int *v47; // r2
  int v48; // r1
  int v49; // r3

  v0 = *(_DWORD *)off_110F94;
  if ( **(__int16 **)off_110F90 < 0 && !v0 )
  {
    sub_1219F4(dword_111130, dword_11112C, 39);
    goto LABEL_10;
  }
  if ( (v0 & 0x2000) != 0 )
  {
    v37 = (unsigned int *)off_11113C;
    v38 = *(_DWORD *)off_111150;
    *(_DWORD *)off_111150 = *(_DWORD *)off_111150;
    v39 = dword_111154;
    v40 = *v37 & 0xFFFFFFDF;
    *v37 = v40;
    sub_11F74C(2, v39, v38, v40);
    if ( (v38 & 4) != 0 )
    {
      v43 = off_11115C;
      v44 = dword_111178;
      *(_BYTE *)off_11115C = 1;
      sub_11F74C(2, v44, 1, v43);
    }
    if ( (v38 & 1) != 0 )
    {
      v42 = off_11115C;
      *(_DWORD *)off_111158 = 16;
      if ( *v42 )
      {
        sub_11F74C(2, dword_111188, 16, (unsigned __int8)*v42);
        *v42 = 0;
      }
      if ( *(_BYTE *)off_111160 )
      {
        v47 = (int *)off_111180;
        *((_BYTE *)off_111160 + 1) = 1;
        v48 = dword_111184;
        v49 = *v47 | 1;
        *v47 = v49;
        sub_11F74C(2, v48, v47, v49);
      }
      *(_BYTE *)off_111164 = 0;
    }
    if ( (v38 & 2) != 0 )
    {
      v45 = off_111164;
      v46 = dword_11117C;
      *(_BYTE *)off_111164 = 1;
      sub_11F74C(2, v46, 1, v45);
    }
    if ( (v38 & 8) != 0 )
      sub_11F504(dword_111168, v41);
  }
  if ( (v0 & 1) != 0 )
  {
    sub_11F504(dword_110F98, v0 << 31);
    *(_DWORD *)off_110F9C = 1;
  }
  if ( (v0 & 0x20) != 0 )
  {
    sub_110C7C(*(_DWORD *)off_110FA0);
    *(_DWORD *)off_110F9C = 32;
  }
  if ( (v0 & 0x4000) != 0 )
  {
    v1 = *(_DWORD *)off_110FA4;
    *(_DWORD *)off_110FA4 = *(_DWORD *)off_110FA4;
    sub_11F504(dword_110FB0, v1);
  }
  if ( (v0 & 0x8000) == 0 )
    goto LABEL_10;
  v31 = dword_111138;
  v32 = *(_DWORD *)off_111134;
  *(_DWORD *)off_111134 = *(_DWORD *)off_111134;
  sub_11F504(v31, v32);
  if ( (v32 & 4) != 0 )
    *(_DWORD *)off_11113C &= ~1u;
  if ( (v32 & 8) == 0 )
  {
LABEL_10:
    v2 = v0 << 9;
    if ( (v0 & 0x400000) == 0 )
      goto LABEL_11;
LABEL_50:
    v33 = dword_111144;
    v34 = *(_DWORD *)off_111140;
    *(_DWORD *)off_111140 = *(_DWORD *)off_111140;
    sub_11F504(v33, v34);
    if ( (v0 & 0x800000) == 0 )
      goto LABEL_12;
    goto LABEL_51;
  }
  v2 = v0 << 9;
  *(_DWORD *)off_11113C &= ~4u;
  if ( (v0 & 0x400000) != 0 )
    goto LABEL_50;
LABEL_11:
  if ( (v0 & 0x800000) == 0 )
    goto LABEL_12;
LABEL_51:
  v35 = dword_11114C;
  v36 = *(_DWORD *)off_111148;
  *(_DWORD *)off_111148 = *(_DWORD *)off_111148;
  sub_11F504(v35, v36);
LABEL_12:
  if ( (v0 & 0x400) != 0 )
  {
    v3 = off_110FB4;
    v4 = *((unsigned __int8 *)off_110FB4 + 1621);
    if ( v4 >= *((unsigned __int8 *)off_110FB4 + 1622) )
    {
      sub_11F504(dword_111174, v4);
    }
    else
    {
      v5 = *(_DWORD *)off_110FBC;
      v6 = *((unsigned __int8 *)off_110FB4 + 1620)
         + 1
         - 81
         * ((unsigned int)(((unsigned int)dword_110FB8
                          * (unsigned __int64)((unsigned int)*((unsigned __int8 *)off_110FB4 + 1620) + 1)) >> 32) >> 6);
      v7 = (char *)off_110FB4 + 20 * v6;
      v8 = off_110FC4;
      *((_DWORD *)v7 + 1) = *(_DWORD *)off_110FC0;
      v3[1621] = v4 + 1;
      v9 = off_110FC8;
      *((_DWORD *)v7 + 2) = *v8;
      v7[12] = v5;
      v3[1620] = v6;
      v7[13] = BYTE1(v5) & 7;
      *v9 = 16;
      do
        v10 = *v9 & 0x20;
      while ( v10 );
      v11 = &v3[20 * v6];
      if ( (v11[13] & 4) == 0 )
        v10 = *(_DWORD *)(*((_DWORD *)v11 + 2) + 4);
      v12 = off_110FD0;
      *(_DWORD *)off_110FCC = v10;
      *v12 = 16;
      sub_11E724(dword_110FD4);
      sub_11E5E0(2048);
    }
    *(_DWORD *)off_110F9C = 1024;
  }
  if ( (v0 & 0x200) != 0 )
  {
    sub_11F504(dword_11116C, v2);
    *(_DWORD *)off_111170 = 512;
  }
  if ( (v0 & 0x100) != 0 )
  {
    v13 = off_110FB4;
    v14 = *((unsigned __int8 *)off_110FB4 + 2433);
    if ( v14 < *((unsigned __int8 *)off_110FB4 + 2434) )
    {
      v27 = *(_DWORD *)off_111014;
      v28 = *(_DWORD *)off_11100C;
      v29 = *((unsigned __int8 *)off_110FB4 + 2432)
          + 1
          - 40
          * ((unsigned int)(((unsigned int)dword_111010
                           * (unsigned __int64)((unsigned int)*((unsigned __int8 *)off_110FB4 + 2432) + 1)) >> 32) >> 5);
      v30 = (char *)off_110FB4 + 20 * v29;
      *((_BYTE *)off_110FB4 + 2432) = v29;
      v30[1645] = BYTE1(v27) & 7;
      *((_DWORD *)v30 + 409) = v28;
      *((_DWORD *)v30 + 410) = v28;
      v30[1644] = v27;
      v13[2433] = v14 + 1;
      sub_11E724(v13 + 2436);
      sub_11E5E0(0x1000000);
    }
    else
    {
      sub_11F504(dword_110FD8, v14);
    }
    *(_DWORD *)off_110F9C = 256;
  }
  result = v0 << 19;
  if ( (v0 & 0x1000) != 0 )
  {
    v16 = off_110FDC;
    v17 = *((unsigned __int8 *)off_110FDC + 3074);
    if ( v17 < *((unsigned __int8 *)off_110FDC + 3073) )
    {
      v24 = *((unsigned __int8 *)off_110FDC + 3072)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)dword_110FF4
                           * (unsigned __int64)((unsigned int)*((unsigned __int8 *)off_110FDC + 3072) + 1)) >> 32) >> 7);
      v25 = (char *)off_110FDC + 16 * v24;
      *((_DWORD *)v25 + 1) = *(_DWORD *)off_111004;
      v26 = off_111008;
      v16[3072] = v24;
      *((_WORD *)v25 + 4) = *v26;
      v16[3074] = v17 + 1;
      sub_11E724(v16 + 3080);
      result = sub_11E5E0(1024);
    }
    else
    {
      result = sub_11F504(dword_110FE0, v17);
    }
    v18 = off_110FE4;
    *(_DWORD *)off_110F9C = 4096;
    if ( !*v18 )
      *(_BYTE *)off_110FE8 &= ~1u;
  }
  if ( (v0 & 0x800) != 0 )
  {
    v19 = off_110FDC;
    v20 = *((unsigned __int8 *)off_110FDC + 6162);
    if ( *((unsigned __int8 *)off_110FDC + 6161) > v20 )
    {
      v22 = *((unsigned __int8 *)off_110FDC + 6160)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)dword_110FF4
                           * (unsigned __int64)((unsigned int)*((unsigned __int8 *)off_110FDC + 6160) + 1)) >> 32) >> 7);
      v23 = off_110FF8;
      *((_BYTE *)off_110FDC + 6160) = v22;
      v19[4 * v22 + 773] = *v23;
      LOWORD(v19[4 * v22 + 774]) = *(_DWORD *)off_110FFC;
      *((_BYTE *)v19 + 6162) = v20 + 1;
      sub_11E724(dword_111000);
      result = sub_11E5E0(512);
    }
    else
    {
      result = sub_11F504(dword_110FEC, v20);
    }
    v21 = off_110FF0;
    *(_DWORD *)off_110F9C = 2048;
    if ( !*v21 )
      *(_BYTE *)off_110FE8 &= ~2u;
  }
  if ( (v0 & 4) != 0 )
    *(_DWORD *)off_110F9C = 4;
  if ( (v0 & 8) != 0 )
    *(_DWORD *)off_110F9C = 8;
  return result;
}

