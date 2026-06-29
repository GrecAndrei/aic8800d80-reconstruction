// sub_119D70 @ 0x119d70, size 190 bytes
int  sub_119D70(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  uint32_t *v5; // r5
  uint32_t *v6; // r3
  int v7; // r4
  BOOL v8; // r0
  int v9; // r3

  v4 = rf_setup_dispatch(5, a4, a3, 28);
  v5 = off_119E30;
  *(uint32_t *)v4 = dword_119E34;
  v6 = off_119E38;
  *(uint32_t *)(v4 + 4) = *v5;
  *(uint32_t *)(v4 + 8) = *v6;
  *(uint16_t *)(v4 + 24) = 4;
  *(uint8_t *)(v4 + 26) = 4;
  v7 = v4;
  read_mac_dual_addr((uint32_t *)(v4 + 12), (uint32_t *)(v4 + 16));
  *(uint32_t *)(v7 + 20) = 0;
  if ( (*v5 & 0x20000) != 0 && phy_get_link_status() )
  {
    *(uint32_t *)(v7 + 20) |= 0x400u;
    if ( (*(uint32_t *)off_119E30 & 0x20000) == 0 )
      goto LABEL_3;
  }
  else if ( (*(uint32_t *)off_119E30 & 0x20000) == 0 )
  {
    goto LABEL_3;
  }
  if ( mmio_get_bit_30() )
    *(uint32_t *)(v7 + 20) |= 0x4000u;
LABEL_3:
  if ( (*(uint32_t *)off_119E30 & 0x2000) != 0 )
    *(uint32_t *)(v7 + 20) |= 0x1000u;
  if ( sub_101A28() )
    *(uint32_t *)(v7 + 20) |= 0x200u;
  if ( (*(uint32_t *)off_119E30 & 0x8000) != 0 && sub_101A2C() )
    *(uint32_t *)(v7 + 20) |= 0x800000u;
  v8 = rf_chip_ready_check();
  v9 = *(uint32_t *)(v7 + 20);
  if ( v8 )
    v9 |= 0x80000u;
  *(uint32_t *)(v7 + 20) = v9 | 0x200000;
  sub_11DE50(v7);
  return 0;
}

