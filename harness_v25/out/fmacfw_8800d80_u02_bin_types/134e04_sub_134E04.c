// sub_134E04 @ 0x134e04, size 166 bytes
// Doc: sub_1234E04 [patch]: Initialize handler table from ROM patches 0x192478/0x18e628/0x16bf80
// sub_1234E04 [patch]: Initialize handler table from ROM patches 0x192478/0x18e628/0x16bf80
// positive sp value has been detected, the output may be wrong!
void  sub_134E04(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  uint32_t *v14; // r5
  int v15; // r11
  int v16; // r7
  int v17; // r4
  int v18; // r9
  int v19; // r10
  int v20; // r12
  uint8_t *v21; // r0
  unsigned int *v22; // r1
  unsigned int v23; // r2
  int *v24; // r3
  char *v25; // r1
  int *v26; // r3
  int v27; // r3
  int v28; // r2
  char v29; // lr
  __int16 v30; // r0
  int v31; // lr
  int v32; // r2
  int v33; // lr
  unsigned int v34; // r0
  unsigned int v35; // r3
  unsigned int v36; // r3
  int v37; // r2
  int v38; // r3
  int v39; // r3
  int v40; // r3
  void *v41; // r1
  unsigned __int16 *v42; // r3
  int v43; // r3
  unsigned int v44; // r0
  uint32_t *v45; // r3
  uint32_t *v46; // r2
  int *v47; // r1
  int v48; // r0
  int v49; // [sp-8h] [bp-1Ch]
  void *v50; // [sp-8h] [bp-1Ch]

  v14 = off_135084;
  v15 = dword_1350CC;
  v16 = *(unsigned __int8 *)(*((uint32_t *)off_135084 + 4) + 61);
  v17 = *((uint32_t *)off_135084 + 5);
  v49 = *((uint32_t *)off_135084 + 4);
  v18 = dword_1350CC + 1320 * v16;
  v19 = *(unsigned __int8 *)(v18 + 116);
  msg_parse(dword_135088);
  v20 = v14[4];
  if ( !v20 )
LABEL_11:
    __asm { POP.W           {R4-R11,PC} }
  v21 = off_13508C;
  v22 = (unsigned int *)off_135090;
  *(uint8_t *)(v17 + 9) = *(uint8_t *)(v49 + 61);
  v23 = *v22 & 0xFFFFFFEF;
  v24 = *((int **)off_135094 + 2);
  *(uint16_t *)v17 = a1;
  *v22 = v23;
  v25 = nullptr;
  v21[13] = 0;
  if ( v24 )
  {
    do
    {
      if ( !*((uint8_t *)v24 + 106) && *((uint8_t *)v24 + 108) )
        ++v25;
      v24 = (int *)*v24;
    }
    while ( v24 );
    if ( a1 )
      goto LABEL_8;
  }
  else
  {
    v25 = nullptr;
    if ( a1 )
    {
LABEL_8:
      v26 = (int *)off_135098;
      *(uint8_t *)(v17 + 8) = (*(uint32_t *)(v20 + 48) & 0x60) != 0;
      if ( *v26 < 0 && !v25 )
      {
        v46 = off_1350C4;
        v21[2] = 0;
        v47 = (int *)off_1350B4;
        v48 = dword_1350C8;
        *v46 |= 0x80000000;
        *v47 = v48;
      }
      sub_12CD34(6u, 10);
      v14[2] = v18;
      *v14 = v17 - 12;
      sub_134800(v18);
LABEL_10:
      feature_guard_check(256, dword_13509C, *(unsigned __int8 *)(v17 + 9), a1, *(unsigned __int16 *)(v17 + 820));
      sub_12CA38(v14[4] - 12);
      v14[4] = 0;
      *((uint8_t *)v14 + 33) = 0;
      goto LABEL_11;
    }
  }
  v27 = v15 + 1320 * v16;
  v28 = dword_1350A0;
  v29 = *(uint8_t *)(v27 + 116);
  *(uint32_t *)(v17 + 2) = *(uint32_t *)(v27 + 368);
  v30 = *(uint16_t *)(v27 + 372);
  *(uint8_t *)(v17 + 10) = v29;
  v31 = *(uint32_t *)(v27 + 72);
  *(uint16_t *)(v17 + 6) = v30;
  *(uint8_t *)(v17 + 11) = *(uint8_t *)(v31 + 24);
  v32 = *(unsigned __int8 *)(v28 + 696 * v19 + 309);
  *(uint8_t *)(v17 + 826) = v32;
  *(uint8_t *)(v17 + 822) = *(uint8_t *)(v27 + 412);
  v33 = *(unsigned __int8 *)(v27 + 413);
  v34 = *(unsigned __int16 *)(v27 + 414);
  *(uint16_t *)(v17 + 824) = v34;
  if ( v33 == v32 )
  {
    *(uint32_t *)(v17 + 828) = *(unsigned __int16 *)(v27 + 416);
  }
  else if ( v32 )
  {
    v35 = *(unsigned __int16 *)(v27 + 416);
    if ( v34 >= v35 )
      v36 = v35 + 20;
    else
      v36 = v35 - 20;
    *(uint32_t *)(v17 + 828) = v36;
  }
  else
  {
    *(uint32_t *)(v17 + 828) = v34;
  }
  v37 = v15 + 1320 * v16;
  v38 = *(uint32_t *)(v37 + 472);
  *(uint32_t *)(v17 + 832) = *(unsigned __int16 *)(v37 + 418);
  v39 = v38 & 1;
  *(uint8_t *)(v17 + 12) = v39;
  if ( v39 )
    LOBYTE(v39) = *(uint8_t *)(v37 + 457);
  *(uint8_t *)(v17 + 13) = v39;
  v40 = v15 + 1320 * v16;
  *(uint8_t *)(v17 + 8) = (*(uint32_t *)(v20 + 48) & 0x60) != 0;
  if ( *(uint8_t *)(v40 + 1224) )
  {
    *(uint32_t *)off_1350A4 = *(unsigned __int16 *)(v40 + 100) | (*(unsigned __int16 *)(v40 + 102) << 16);
    *(uint32_t *)off_1350A8 = *(unsigned __int16 *)(v40 + 104);
    *(uint32_t *)off_1350AC = *(unsigned __int16 *)(v40 + 64) | (*(unsigned __int16 *)(v40 + 66) << 16);
    *(uint32_t *)off_1350B0 = *(unsigned __int16 *)(v40 + 68);
  }
  v50 = v25;
  sdio_buffer_prepare_n_4e8(v17);
  v41 = v50;
  *(uint32_t *)off_1350B4 = dword_1350B8;
  if ( v50 == (void *)1 )
  {
    v42 = (unsigned __int16 *)(v15 + 1320 * v16);
    v41 = off_1350A4;
    *(uint32_t *)off_1350A4 = v42[50] | (v42[51] << 16);
    *(uint32_t *)off_1350A8 = v42[52];
  }
  if ( *(uint8_t *)(v15 + 1320 * v16 + 413) == 2 )
    sub_12077C((int *)v18, 0, 1);
  v43 = v15 + 1320 * v16;
  v44 = *(unsigned __int16 *)(v43 + 416);
  if ( v44 <= 0x1387 )
    mmio_init_or_reset(v44 | (*(unsigned __int8 *)(v43 + 413) << 16) | 0x80000000, (int)v41, 4999);
  v45 = off_1350BC;
  *(uint8_t *)(v15 + 1320 * v16 + 149) = 1;
  timestamp_update(1320 * v16 + 152 + v15, dword_1350C0 + v45[4]);
  sub_12CD34(6u, 0);
  goto LABEL_10;
}

