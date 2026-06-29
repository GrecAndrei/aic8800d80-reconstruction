// sub_13623C @ 0x13623c, size 140 bytes
int sub_13623C()
{
  __int16 **v0; // r4

  v0 = (__int16 **)off_1362C8;
  if ( **(__int16 **)off_1362C8 < 0 && sub_12CD48(7u) != 1 && sub_12CD48(7u) && sub_12CD48(7u) != 3 )
    sub_12F32C(dword_1362D8, dword_1362D0, 341);
  if ( sub_12CD48(7u) == 1 )
  {
    if ( **v0 < 0 && *((uint32_t *)off_1362CC + 1) )
      sub_12F32C(dword_1362D4, dword_1362D0, 349);
    sub_13684C();
  }
  else if ( sub_12CD48(7u) == 3 )
  {
    sub_12C8D0(7171, 13, 7);
    sub_12CBF4(7u, 0);
  }
  return 0;
}

