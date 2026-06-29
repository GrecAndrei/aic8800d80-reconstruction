// sub_117954 @ 0x117954, size 50 bytes
int  sub_117954(int a1)
{
  void *v2; // r0

  sub_11739C(a1, *(uint32_t *)(a1 + 28));
  v2 = off_117988;
  if ( !*(uint32_t *)off_117988 )
    return sub_1174EC(a1);
  *(uint8_t *)(a1 + 16) |= 1u;
  *(uint32_t *)(a1 + 4) = 0;
  return sub_11E724(v2);
}

