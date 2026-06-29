// sub_117DD8 @ 0x117dd8, size 44 bytes
int  sub_117DD8(int a1, int a2, int a3)
{
  int v3; // r3
  int v5; // r0
  int result; // r0

  v3 = *(uint32_t *)(a1 + 76);
  v5 = dword_117E04;
  *(uint32_t *)(v3 + 4) = a2;
  result = sub_12D108(v5 + 8 * a3);
  if ( (*(uint32_t *)(a1 + 36) & 0x200000) == 0 )
    return sub_12CFC4(*(uint32_t *)(dword_117E08 + 4 * a3));
  return result;
}

