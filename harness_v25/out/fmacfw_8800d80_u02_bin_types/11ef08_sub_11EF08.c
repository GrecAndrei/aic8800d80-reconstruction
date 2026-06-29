// sub_11EF08 @ 0x11ef08, size 504 bytes
int  sub_11EF08(int *a1, uint8_t *a2)
{
  int v3; // r8
  int v5; // r0
  int v6; // r4
  int v7; // r7
  int *v8; // r2
  int v9; // r1
  int v10; // r3
  unsigned int v11; // r0
  char v12; // r3
  int v13; // r1
  char v14; // r3
  int v15; // r0
  int v16; // r3
  int v17; // r2
  int v18; // r2
  int v19; // r3
  int v20; // r8
  int v21; // r1
  int v22; // r12
  uint32_t *v23; // r1
  int v24; // r2
  int v25; // r2
  int v26; // r1
  int v27; // r2
  uint32_t *v28; // r3
  int v29; // r0
  int v30; // r2
  int v31; // r1
  uint32_t *v32; // r1
  unsigned int v33; // r3
  int v35; // r0
  char v36; // r1
  __int16 v37; // r12
  __int16 v38; // r3
  __int16 v39; // r1
  __int16 v40; // r3
  int v41; // r1

  v3 = *((unsigned __int8 *)a1 + 25);
  v5 = rf_bus_mark_n100_d2d0(dword_11F100);
  if ( !v5 )
    return 1;
  v6 = v5;
  if ( *((uint8_t *)a1 + 29) )
  {
    v35 = rf_bus_mark_n100_d2d0(dword_11F100);
    if ( !v35 )
    {
      list_push_tail(dword_11F100);
      return 1;
    }
    *(uint32_t *)(v6 + 44) = v35;
    *(uint32_t *)(v35 + 44) = v6;
    v36 = *((uint8_t *)a1 + 30);
    v8 = (int *)((char *)a1 + 18);
    v37 = *((unsigned __int8 *)a1 + 29);
    *(uint32_t *)(v35 + 38) = *(int *)((char *)a1 + 18);
    *(uint16_t *)(v35 + 42) = *((uint16_t *)a1 + 11);
    v7 = dword_11F104;
    v38 = ((1 << v36) - 1) << 8;
    v39 = *(uint16_t *)(v35 + 42) & ~v38;
    *(uint16_t *)(v35 + 42) = v39;
    v40 = v38 & (*((uint16_t *)a1 + 11) - (v37 << 8)) | v39;
    v41 = dword_11F108 * ((v35 - v7) >> 3);
    *(uint16_t *)(v35 + 42) = v40;
    *(uint8_t *)(v35 + 35) = v41;
    *(uint16_t *)(v35 + 32) = -1;
  }
  else
  {
    v7 = dword_11F104;
    v8 = (int *)((char *)a1 + 18);
  }
  v9 = *v8;
  v10 = *a1;
  *(uint16_t *)(v6 + 42) = *((uint16_t *)v8 + 2);
  *(uint32_t *)(v6 + 38) = v9;
  *(uint32_t *)(v6 + 4) = v10;
  v11 = *((unsigned __int8 *)a1 + 24);
  v12 = dword_11F108;
  v13 = dword_11F110;
  if ( v11 < 0x10 )
    LOBYTE(v11) = 16;
  *(uint8_t *)(v6 + 28) = v11;
  *(uint16_t *)(v6 + 20) = *((uint16_t *)a1 + 8);
  *(uint32_t *)(v6 + 16) = a1[2];
  *(uint32_t *)(v6 + 12) = a1[1];
  *(uint32_t *)(v6 + 24) = a1[3];
  v14 = v12 * ((v6 - v7) >> 3);
  *(uint8_t *)(v6 + 34) = *((uint8_t *)a1 + 25);
  *a2 = v14;
  *(uint8_t *)(v6 + 35) = v14;
  feature_guard_check(256, v13);
  v15 = dword_11F114;
  v16 = dword_11F114 + 1320 * v3;
  v17 = *(unsigned __int8 *)(v16 + 1224);
  *(uint32_t *)(v6 + 8) = 102400;
  if ( v17 )
    ++*(uint8_t *)(v16 + 1226);
  *(uint16_t *)(v6 + 552) = -1;
  v18 = v6 + 552;
  v19 = v6;
  do
  {
    *(uint16_t *)(v18 + 2) = -1;
    v18 += 2;
  }
  while ( v18 != v6 + 570 );
  v20 = 1320 * v3;
  v21 = (unsigned __int8)*a2;
  *(uint8_t *)(v6 + 52) = 0;
  v22 = *(uint32_t *)(v15 + v20 + 1208);
  *(uint32_t *)(v6 + 336) = dword_11F118 + (v21 << 6);
  v23 = off_11F11C;
  if ( (v22 & 8) != 0 )
    v24 = v6 + 184;
  else
    v24 = v20 + 1200;
  if ( (v22 & 8) == 0 )
    v24 += v15;
  *(uint32_t *)(v6 + 188) = v24;
  v25 = v23[4];
  v26 = v25 - 1000000;
  v27 = v25 - 500000;
  do
  {
    *(uint32_t *)(v19 + 444) = v26;
    *(uint32_t *)(v19 + 448) = v27;
    v19 += 12;
  }
  while ( v6 + 108 != v19 );
  if ( (v22 & 0x10) != 0 )
    *(uint32_t *)(v6 + 4) |= 8u;
  list_push_tail(v15 + v20 + 240);
  *(uint32_t *)(v6 + 580) = dword_11F120;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11F124 = 1;
  }
  v28 = off_11F128;
  v29 = *(uint32_t *)(v6 + 44);
  v30 = *(uint32_t *)off_11F128;
  v31 = *(uint32_t *)off_11F128 + 1;
  *(uint32_t *)off_11F128 = v31;
  *(uint8_t *)(v6 + 37) = 1;
  if ( v29 )
    *(uint8_t *)(v29 + 37) = 1;
  if ( v31 )
  {
    v32 = off_11F124;
    *v28 = v30;
    if ( !v30 )
    {
      if ( *v32 )
        __enable_irq();
    }
  }
  v33 = (unsigned __int8)*a2;
  if ( v33 <= 0x23 )
    *(uint32_t *)(v7 + 696 * v33 + 664) = *((uint32_t *)off_11F11C + 4);
  *(uint8_t *)(v6 + 668) = 0;
  return 0;
}

