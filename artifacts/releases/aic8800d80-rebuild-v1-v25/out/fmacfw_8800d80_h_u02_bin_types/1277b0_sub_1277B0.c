// sub_1277B0 @ 0x1277b0, size 94 bytes
int  sub_1277B0(int a1)
{
  int result; // r0
  char v3; // r3
  int v4; // r3

  result = sub_124BFC(a1 + 24, *(uint32_t *)(a1 + 36) + *(uint32_t *)(a1 + 88));
  v3 = *(uint8_t *)(a1 + 85);
  *(uint8_t *)(a1 + 85) = v3 & 0xDF;
  if ( (v3 & 1) != 0 )
  {
    v4 = *((uint32_t *)off_127810 + 9);
    if ( v4 && *(uint32_t *)(v4 + 12) == a1 + 76 )
    {
      sub_1266A0();
      sub_126444(a1, *(uint32_t *)(a1 + 36), 0);
      return sub_1266E4(a1, *((uint32_t *)off_127814 + 4), 0);
    }
    else
    {
      return sub_126444(a1, *(uint32_t *)(a1 + 36), 0);
    }
  }
  return result;
}

