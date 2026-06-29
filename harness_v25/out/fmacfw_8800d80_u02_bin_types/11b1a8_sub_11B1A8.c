// sub_11B1A8 @ 0x11b1a8, size 72 bytes
int  sub_11B1A8(int a1, int a2)
{
  int v4; // r5
  int v5; // r8
  int v6; // r2

  v4 = dword_11B1F0 + 84 * a2;
  v5 = *(uint32_t *)(a1 + 76);
  rf_bus_mark_n100_d2d0(84 * (__int16)a2 + 12 + dword_11B1F0);
  v6 = *(unsigned __int16 *)(a1 + 4);
  --*(uint8_t *)(v4 + 80);
  if ( v6 )
    return sub_117F18(a1, *(uint32_t *)(v5 + 72), a2);
  else
    return sub_118CE0();
}

