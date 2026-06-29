// sub_141C90 @ 0x141c90, size 102 bytes
int  sub_141C90(int a1)
{
  int v1; // r2
  int v3; // r3
  uint64_t v4; // r0
  int v5; // r5
  uint8_t *v6; // r2
  int v7; // r3
  __int16 v8; // r1
  int result; // r0
  int v10; // r1

  v1 = *(uint32_t *)(a1 + 12);
  v3 = *((uint32_t *)off_141CF8 + 4) + 100;
  v4 = *(QWORD *)(a1 + 24) + *(unsigned int *)(a1 + 16);
  *(uint32_t *)(a1 + 56) = dword_141CFC;
  *(QWORD *)(a1 + 24) = v4;
  v5 = *(unsigned __int8 *)(a1 + 47);
  sub_124BFC(a1 + 52, v3 + v1);
  v6 = off_141D04;
  v7 = dword_141D00 + 1320 * v5;
  v8 = *(uint16_t *)a1 | 8;
  result = *(uint32_t *)(v7 + 4) | 0x100;
  *(uint32_t *)(v7 + 4) = result;
  *(uint16_t *)a1 = v8;
  v10 = *(unsigned __int8 *)(a1 + 4);
  ++v6[1];
  if ( !v10 )
  {
    result = *(unsigned __int8 *)(a1 + 47);
    v6[2] |= 1 << result;
  }
  return result;
}

