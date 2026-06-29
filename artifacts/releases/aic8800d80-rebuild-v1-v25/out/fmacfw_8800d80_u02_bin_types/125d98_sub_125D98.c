// sub_125D98 @ 0x125d98, size 42 bytes
int  sub_125D98(int a1)
{
  uint8_t *v2; // r0
  uint32_t *v3; // r2

  v2 = (uint8_t *)sub_12C92C(72, *(unsigned __int16 *)(a1 + 14), 0, 2);
  v2[1] = *(uint8_t *)(a1 + 24);
  v3 = off_125DC4;
  *v2 = *(uint8_t *)(a1 + 26);
  *v3 &= ~4u;
  return sdio_buffer_prepare_n_4e8(v2);
}

