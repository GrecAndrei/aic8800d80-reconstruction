// sub_10D3AC @ 0x10d3ac, size 66 bytes
int  sub_10D3AC(int result)
{
  if ( result == 1 )
  {
    *(uint32_t *)off_10D3F0 = 0x40000;
  }
  else if ( result == 2 )
  {
    *(uint32_t *)off_10D3F0 = 0x80000;
  }
  else if ( **(__int16 **)off_10D3F8 < 0 )
  {
    result = sub_12F46C(dword_10D400, dword_10D3FC, 2118);
  }
  *((uint32_t *)off_10D3F4 + 1) |= 0x400000u;
  return result;
}

