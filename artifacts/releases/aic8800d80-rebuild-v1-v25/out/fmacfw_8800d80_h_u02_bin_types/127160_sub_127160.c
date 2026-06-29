// sub_127160 @ 0x127160, size 134 bytes
int sub_127160()
{
  uint8_t *v0; // r4
  int v1; // r3
  int result; // r0

  v0 = off_1271E8;
  v1 = *((unsigned __int8 *)off_1271E8 + 88);
  result = v1 << 31;
  if ( (v1 & 1) != 0 )
  {
    if ( **(__int16 **)off_1271EC < 0 && (v1 & 4) != 0 )
    {
      sub_12F32C(dword_1271FC, dword_1271F8, 1720);
      LOBYTE(v1) = v0[88];
    }
    v0[88] = v1 & 0xFA | 4;
    return sub_127030(dword_1271F0);
  }
  else if ( (v1 & 6) == 2 )
  {
    if ( **(__int16 **)off_1271EC < 0 && (v1 & 8) != 0 )
    {
      sub_12F32C(dword_127200, dword_1271F8, 1731);
      LOBYTE(v1) = v0[88];
    }
    v0[88] = v1 & 0xF5 | 8;
    return sub_127030(dword_1271F4);
  }
  return result;
}

