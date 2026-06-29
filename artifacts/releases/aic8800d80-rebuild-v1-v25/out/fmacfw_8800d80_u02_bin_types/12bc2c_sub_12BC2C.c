// sub_12BC2C @ 0x12bc2c, size 110 bytes
unsigned int sub_12BC2C()
{
  uint32_t *v0; // r2
  uint32_t *v1; // r0
  __int16 **v2; // r5
  int *v3; // r4
  int v4; // r3
  __int16 *v5; // r2
  unsigned int result; // r0
  uint32_t *v7; // r2

  v0 = off_12BC9C;
  v1 = off_12BCA0;
  *(uint32_t *)off_12BC9C &= ~1u;
  v2 = (__int16 **)off_12BCA4;
  v3 = (int *)off_12BCA8;
  v4 = dword_12BCAC;
  *v0 &= ~2u;
  *v1 |= 0x700u;
  v5 = *v2;
  *v3 = v4;
  if ( *v5 < 0 && *(uint32_t *)off_12BCB4 << 28 )
  {
    sub_12F49C(dword_12BCBC, dword_12BCB8, 472);
    v4 = *v3;
  }
  *(uint32_t *)off_12BCB0 = v4 | v3[1];
  result = mmio_reg_bit_modify(1);
  v7 = off_12BCA0;
  *(uint32_t *)off_12BCA0 = *(uint32_t *)off_12BCA0 & 0xFFFE3FFF | 0x10000;
  *v7 |= 0x2000u;
  return result;
}

