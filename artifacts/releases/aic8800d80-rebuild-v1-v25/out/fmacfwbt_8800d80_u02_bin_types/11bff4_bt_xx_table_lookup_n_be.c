// bt_xx_table_lookup_n_be @ 0x11bff4, size 68 bytes
// Doc: bt_xx_table_lookup_n_be [bt]: Looks up table entry indexed by [base+0xbe] scaled by 0x54
// bt_xx_table_lookup_n_be [bt]: Looks up table entry indexed by [base+0xbe] scaled by 0x54
int  bt_xx_table_lookup_n_be(int a1, int a2)
{
  int v2; // r6
  int v3; // r5
  int result; // r0
  int v6; // r5

  v2 = dword_11C03C;
  v3 = *((unsigned __int8 *)off_11C038 + 190);
  sub_12D4F8(dword_11C03C + 84 * v3 + 12);
  result = sub_118358(a1, a2, v3);
  if ( (*(uint32_t *)(a1 + 36) & 0x380000) == 0x380000 )
  {
    v6 = v2 + 84 * v3;
    *(uint32_t *)(v6 + 36) = *(uint32_t *)(a1 + 68);
    *(uint8_t *)(v6 + 26) = 2;
  }
  return result;
}

