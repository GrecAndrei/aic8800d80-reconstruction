// sub_1337CC @ 0x1337cc, size 52 bytes
uint32_t * sub_1337CC(uint32_t *result, int *a2, int a3)
{
  int v3; // r2
  int v4; // r4
  unsigned int v5; // r2
  unsigned int v6; // r3
  unsigned int v7; // r2
  int v8; // r3
  unsigned int v9; // r2
  int v10; // r3

  v3 = a3 ^ *result;
  v4 = *a2 ^ __ROR4__(v3, 15);
  v5 = v3 + v4;
  v6 = ((v5 >> 8) & 0xFF00FF | (v5 << 8) & 0xFF00FF00) ^ v4;
  v7 = v5 + v6;
  v8 = v6 ^ __ROR4__(v7, 29);
  v9 = v7 + v8;
  v10 = v8 ^ __ROR4__(v9, 2);
  *a2 = v10;
  *result = v9 + v10;
  return result;
}

