// fwstruct annotate: 10d3ac_sub_10D3AC.c
// sub_10D3AC @ 0x10d3ac, size 66 bytes
int __fastcall sub_10D3AC(int result)
{
  if ( result == 1 )
  {
    *(_DWORD *)off_10D3F0 = 0x40000;
  }
  else if ( result == 2 )
  {
    *(_DWORD *)off_10D3F0 = 0x80000;
  }
  else if ( **(__int16 **)off_10D3F8 < 0 )
  {
    result = sub_12F46C(dword_10D400, dword_10D3FC, 2118);
  }
  *((_DWORD *)off_10D3F4 + 1) |= 0x400000u;
  return result;
}

