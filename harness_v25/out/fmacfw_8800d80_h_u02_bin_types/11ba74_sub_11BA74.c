// sub_11BA74 @ 0x11ba74, size 68 bytes
int  sub_11BA74(int a1, int a2)
{
  int v2; // r6
  int v3; // r5
  int result; // r0
  int v6; // r5

  v2 = dword_11BABC;
  v3 = *((unsigned __int8 *)off_11BAB8 + 190);
  sub_12D190(dword_11BABC + 84 * v3 + 12);
  result = sub_117DD8(a1, a2, v3);
  if ( (*(uint32_t *)(a1 + 36) & 0x380000) == 0x380000 )
  {
    v6 = v2 + 84 * v3;
    *(uint32_t *)(v6 + 36) = *(uint32_t *)(a1 + 68);
    *(uint8_t *)(v6 + 26) = 2;
  }
  return result;
}

