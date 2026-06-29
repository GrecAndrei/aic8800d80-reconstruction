// sub_10DD70 @ 0x10dd70, size 40 bytes
int  sub_10DD70(int a1)
{
  int v1; // r2
  int v2; // r0
  int v3; // r1

  v1 = dword_10DD98;
  v2 = 4 * a1;
  v3 = dword_10DD98 + 192;
  do
  {
    *(uint32_t *)(v1 - 12) = *(uint32_t *)(v1 - 12) & 0xFFFFFFF3 | v2;
    v1 += 12;
  }
  while ( v1 != v3 );
  return sub_102D10(1, 16, 0x10u, dword_10DD9C);
}

