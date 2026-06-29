// sub_13CC18 @ 0x13cc18, size 108 bytes
// Doc: rf_chan_cfg_set [rf]: Set RF channel config bits from args
// rf_chan_cfg_set [rf]: Set RF channel config bits from args
unsigned int * sub_13CC18(unsigned int *result)
{
  uint64_t v1; // r2
  int v2; // r1
  unsigned int v3; // r5
  unsigned int v4; // r7
  unsigned int v5; // r1

  v1 = *(QWORD *)(result + 1);
  v2 = dword_13CC84;
  v3 = *result;
  v4 = result[3];
  *result = dword_13CC84 & (*result >> 15) | ((uint32_t)v1 << 17) & 0x1000000 | (2 * *result) & 0xFEFEFEFE;
  LODWORD(v1) = (2 * v1) & 0xFEFEFEFE | v2 & ((unsigned int)v1 >> 15) | (HIDWORD(v1) << 17) & 0x1000000;
  HIDWORD(v1) = (2 * HIDWORD(v1)) & 0xFEFEFEFE | v2 & (HIDWORD(v1) >> 15) | (v4 << 17) & 0x1000000;
  v5 = v2 & (v4 >> 15) | (2 * v4) & 0xFEFEFEFE;
  *(QWORD *)(result + 1) = v1;
  if ( (v3 & 0x80) != 0 )
    v5 ^= 0x87000000;
  result[3] = v5;
  return result;
}

