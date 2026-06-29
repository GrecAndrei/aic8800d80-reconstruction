// sub_11B7C8 @ 0x11b7c8, size 100 bytes
uint32_t * sub_11B7C8(uint32_t *result)
{
  uint32_t *v1; // r2
  int v2; // r5
  uint32_t *v3; // r4
  uint32_t *v4; // r2
  uint32_t *v5; // r3
  uint32_t *v6; // r6
  int v7; // r4
  int v8; // r1
  uint32_t *v9; // r5

  v1 = off_11B834;
  v2 = result[9];
  v3 = off_11B838;
  *(uint32_t *)off_11B830 = *(uint32_t *)off_11B82C + 20000;
  *v1 = 64;
  v4 = off_11B83C;
  v5 = off_11B840;
  v6 = off_11B844;
  *v3 |= 0x40u;
  v5[275] = *(uint32_t *)(v2 + 12);
  v7 = v4[52];
  v8 = result[15];
  v5[276] = *(uint32_t *)(v2 + 16);
  v4[52] = v7 | 1;
  v9 = off_11B848;
  result[9] = v5 + 272;
  result[15] = v8 & 0xFF00;
  result[1] = 0;
  *((uint8_t *)v4 + 200) = 0;
  *v6 = result;
  *v9 = 0x2000;
  return result;
}

