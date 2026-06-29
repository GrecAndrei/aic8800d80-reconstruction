// sub_10DEF0 @ 0x10def0, size 72 bytes
int sub_10DEF0()
{
  uint32_t *v0; // r3
  uint64_t v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0
  int v4; // r0

  while ( *((uint32_t *)off_10DF50 + 7) != 1 )
    ;
  v0 = off_10DF50;
  *((uint32_t *)off_10DF50 + 7) = 1;
  v1 = sub_12752C(v0[4]);
  v2 = sub_127620(v1, HIDWORD(v1), dword_10DF38, dword_10DF3C);
  v3 = sub_127874(v2, HIDWORD(v2), dword_10DF40, dword_10DF44);
  v4 = sub_1272B0(v3, HIDWORD(v3), dword_10DF48, dword_10DF4C);
  return sub_127BE4(v4);
}

