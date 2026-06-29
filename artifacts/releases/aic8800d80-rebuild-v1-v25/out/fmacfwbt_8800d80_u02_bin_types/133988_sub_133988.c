// sub_133988 @ 0x133988, size 68 bytes
uint32_t * sub_133988(int a1)
{
  int v1; // r5
  unsigned int v2; // r2
  uint32_t *v4; // r0
  int *v5; // r1

  v1 = *(uint32_t *)(a1 + 8);
  v2 = *(unsigned __int8 *)(a1 + 12);
  if ( **(__int16 **)off_1339CC < 0 && v2 > 3 )
  {
    sub_12F694(dword_1339D4, dword_1339D0, 321);
    LOBYTE(v2) = *(uint8_t *)(a1 + 12);
  }
  v4 = xtea_block_decrypt((uint32_t *)a1, (int *)(a1 + 4), (90 << (8 * v2)) | v1);
  return xtea_block_decrypt(v4, v5, 0);
}

