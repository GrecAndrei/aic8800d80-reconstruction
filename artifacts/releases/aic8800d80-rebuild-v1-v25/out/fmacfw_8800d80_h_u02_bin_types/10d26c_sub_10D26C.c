// sub_10D26C @ 0x10d26c, size 66 bytes
int  sub_10D26C(int result)
{
  if ( result == 1 )
  {
    *(uint32_t *)off_10D2B0 = 0x40000;
  }
  else if ( result == 2 )
  {
    *(uint32_t *)off_10D2B0 = 0x80000;
  }
  else if ( **(__int16 **)off_10D2B8 < 0 )
  {
    result = sub_12F32C(dword_10D2C0, dword_10D2BC, 2118);
  }
  *((uint32_t *)off_10D2B4 + 1) |= 0x400000u;
  return result;
}

