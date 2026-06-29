// sub_129768 @ 0x129768, size 82 bytes
int  sub_129768(int a1, int a2)
{
  int v4; // r0
  int v5; // r3
  int v6; // r2
  uint64_t v7; // kr00_8

  v4 = rf_bus_setup_n3a8(85, 13, 0, 16);
  *(uint8_t *)v4 = *(uint8_t *)(a1 + 113);
  v5 = a1 + 48 * a2;
  *(uint8_t *)(v4 + 1) = a2;
  if ( *(uint8_t *)(v5 + 16) )
  {
    v6 = *(unsigned __int8 *)(v5 + 20);
    *(uint8_t *)(v4 + 3) = v6;
    if ( v6 )
    {
      *(uint8_t *)(v4 + 2) = *(uint8_t *)(v5 + 32);
      v7 = *(QWORD *)(v5 + 24);
      *(uint32_t *)(v4 + 12) = *(uint32_t *)(v5 + 36);
      *(QWORD *)(v4 + 4) = v7;
    }
  }
  else
  {
    *(uint8_t *)(v4 + 3) = 0;
  }
  return sub_12CBB4(v4);
}

