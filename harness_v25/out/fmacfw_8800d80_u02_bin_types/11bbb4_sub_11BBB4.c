// sub_11BBB4 @ 0x11bbb4, size 68 bytes
int  sub_11BBB4(int a1, int a2)
{
  int v2; // r6
  int v3; // r5
  int result; // r0
  int v6; // r5

  v2 = dword_11BBFC;
  v3 = *((unsigned __int8 *)off_11BBF8 + 190);
  rf_bus_mark_n100_d2d0(dword_11BBFC + 84 * v3 + 12);
  result = sub_117F18(a1, a2, v3);
  if ( (*(uint32_t *)(a1 + 36) & 0x380000) == 0x380000 )
  {
    v6 = v2 + 84 * v3;
    *(uint32_t *)(v6 + 36) = *(uint32_t *)(a1 + 68);
    *(uint8_t *)(v6 + 26) = 2;
  }
  return result;
}

