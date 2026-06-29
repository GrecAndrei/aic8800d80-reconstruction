// rf_msg_alloc_init @ 0x11b80c, size 420 bytes
// Doc: rf_msg_alloc_init [ipc]: Allocates and initializes RF message buffer from pool
// rf_msg_alloc_init [ipc]: Allocates and initializes RF message buffer from pool
int rf_msg_alloc_init()
{
  uint32_t *v0; // r5
  uint32_t *v1; // r6
  int v2; // r4
  uint8_t *v3; // r0
  int v4; // r3
  __int16 v5; // r3
  BOOL v6; // r7
  int v7; // r3
  unsigned int v8; // r3
  int v9; // r5
  int v10; // r7
  int v11; // r1
  unsigned int v13; // r3
  int v14; // r2
  int v15; // r3

  v0 = off_11B9B0;
  v1 = off_11B9B4;
  v2 = *((uint32_t *)off_11B9B0 + 11);
  sub_102908((unsigned __int8 *)(v2 + 4), 0);
  sub_11D9F8(*(char *)(v2 + 12));
  *(uint32_t *)off_11B9B8 = v1[*(unsigned __int8 *)(v2 + 4) + 5];
  if ( *(uint8_t *)(v2 + 24) == 3 )
  {
    v7 = v0[10];
    if ( !v7 )
    {
      v0[10] = v2;
      v0[11] = 0;
      *(uint8_t *)(v2 + 16) = 4;
      if ( *((uint8_t *)v0 + 90) || !*((uint8_t *)off_11B9BC + 143) )
        goto LABEL_31;
      goto LABEL_29;
    }
    v6 = 0;
    goto LABEL_7;
  }
  v3 = (uint8_t *)rf_setup_dispatch(68, 4, 0, 4);
  v4 = *(unsigned __int8 *)(v2 + 24);
  *v3 = v4;
  if ( v4 == 4 )
  {
    v5 = *(uint16_t *)(v2 + 14);
    if ( v5 )
      LOBYTE(v5) = 1;
  }
  else
  {
    LOBYTE(v5) = 0;
  }
  v6 = 0;
  v3[1] = v5;
  v3[3] = 0;
  v3[2] = *(uint8_t *)(v2 + 26);
  sub_11DE50(v3);
  v7 = v0[10];
  if ( v7 )
  {
    if ( *(uint8_t *)(v2 + 24) == 4
      && *(unsigned __int16 *)(v7 + 4) == *(unsigned __int16 *)(v2 + 4)
      && *(unsigned __int8 *)(v7 + 13) == *(unsigned __int8 *)(v2 + 13)
      && *(unsigned __int16 *)(v7 + 6) == *(unsigned __int16 *)(v2 + 6)
      && *(unsigned __int16 *)(v7 + 8) == *(unsigned __int16 *)(v2 + 8) )
    {
      v6 = *(unsigned __int16 *)(v7 + 10) == *(unsigned __int16 *)(v2 + 10);
    }
LABEL_7:
    *(uint8_t *)(v7 + 16) = 1;
    v8 = *(unsigned __int8 *)(v2 + 24);
    goto LABEL_8;
  }
  v6 = 0;
  v8 = *(unsigned __int8 *)(v2 + 24);
LABEL_8:
  v0[10] = v2;
  v0[11] = 0;
  *(uint8_t *)(v2 + 16) = 4;
  if ( v8 > 2 )
  {
    if ( *((uint8_t *)v0 + 90) && !v6 || !*((uint8_t *)off_11B9BC + 143) )
    {
      if ( v8 != 3 )
        return mmio_init_clock_gate_n121();
      goto LABEL_31;
    }
    goto LABEL_29;
  }
  if ( *((uint8_t *)off_11B9BC + 143) )
  {
LABEL_29:
    patch_table_apply_dbc();
    v13 = *(unsigned __int8 *)(v2 + 24);
    if ( v13 <= 2 )
      goto LABEL_10;
    if ( v13 != 3 )
      return mmio_init_clock_gate_n121();
LABEL_31:
    v14 = **(__int16 **)off_11B9C8;
    v15 = v1[1] | 0x2200;
    *(uint32_t *)off_11B9CC = 0;
    v1[1] = v15;
    if ( v14 < 0 && *(uint32_t *)off_11B9D4 << 28 )
    {
      sub_1219F4(dword_11B9DC, dword_11B9D8, 472);
      v15 = v1[1];
    }
    *(uint32_t *)off_11B9D0 = v15 | *v1;
    sub_11DED8(141, 2, 255);
    return mmio_init_clock_gate_n121();
  }
LABEL_10:
  sub_11B6F0();
  v9 = *((uint32_t *)off_11B9C0 + 2);
  if ( v9 )
  {
    v10 = dword_11B9C4;
    do
    {
      while ( *(uint32_t *)(v9 + 72) != v2 )
      {
        v9 = *(uint32_t *)v9;
        if ( !v9 )
          goto LABEL_15;
      }
      *(uint8_t *)(v10 + 32 * *(unsigned __int8 *)(v9 + 95) + 31) = 1;
      rf_init_or_setup_n32c(v9);
      v9 = *(uint32_t *)v9;
    }
    while ( v9 );
  }
LABEL_15:
  v11 = *(unsigned __int16 *)(v2 + 14);
  if ( v11 != 255 )
  {
    sub_11DED8(62, v11, 0);
    *(uint16_t *)(v2 + 14) = 255;
  }
  return mmio_init_clock_gate_n121();
}

