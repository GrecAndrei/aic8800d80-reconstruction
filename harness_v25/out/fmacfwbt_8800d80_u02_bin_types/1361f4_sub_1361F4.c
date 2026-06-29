// sub_1361F4 @ 0x1361f4, size 68 bytes
int  sub_1361F4(int a1, unsigned __int8 *a2, __int16 a3, __int16 a4)
{
  unsigned __int16 v5; // r7
  uint8_t *v8; // r0

  v5 = *((uint16_t *)a2 + 1);
  sub_14380C(dword_136238 + (*a2 << 9), a2 + 4, v5);
  *(uint16_t *)(dword_13623C + 2 * *a2) = v5;
  v8 = (uint8_t *)rf_bus_setup_n3a8(7177, a4, a3, 2u);
  *v8 = 1;
  v8[1] = *a2;
  sub_12CBB4((int)v8);
  return 0;
}

