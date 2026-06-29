// sub_1286F4 @ 0x1286f4, size 74 bytes
BOOL  sub_1286F4(int a1)
{
  int v1; // r3
  unsigned int v2; // r1

  v1 = *((uint32_t *)off_128740 + 10);
  if ( !v1 )
    return 0;
  v2 = *(unsigned __int8 *)(v1 + 24);
  if ( v2 <= 2 )
    return *(uint32_t *)(a1 + 72) == v1;
  if ( *(uint32_t *)(a1 + 72) && !*(uint8_t *)(a1 + 1224) && v2 == 4 )
    return sub_1286B4(a1);
  return *(unsigned __int8 *)(v1 + 26) == *(unsigned __int8 *)(a1 + 107);
}

