// sub_10D204 @ 0x10d204, size 66 bytes
int  sub_10D204(int result)
{
  if ( result == 1 )
  {
    *(uint32_t *)off_10D248 = 0x40000;
  }
  else if ( result == 2 )
  {
    *(uint32_t *)off_10D248 = 0x80000;
  }
  else if ( **(__int16 **)off_10D250 < 0 )
  {
    result = sub_12F694(dword_10D258, dword_10D254, 2118);
  }
  *((uint32_t *)off_10D24C + 1) |= 0x400000u;
  return result;
}

