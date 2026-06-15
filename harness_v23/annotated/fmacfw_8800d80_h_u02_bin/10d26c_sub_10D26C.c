// v23 annotated: sub_10D26C @ 0x10d26c
// Original: 10d26c_sub_10D26C.c
// Primary struct: <unclustered>
//
// sub_10D26C @ 0x10d26c, size 66 bytes
int __fastcall sub_10D26C(int result)
{
  if ( result == 1 )
  {
    *(_DWORD *)off_10D2B0 = 0x40000;
  }
  else if ( result == 2 )
  {
    *(_DWORD *)off_10D2B0 = 0x80000;
  }
  else if ( **(__int16 **)off_10D2B8 < 0 )
  {
    result = sub_12F32C(dword_10D2C0, dword_10D2BC, 2118);
  }
  *((_DWORD *)off_10D2B4 + 1) |= 0x400000u;
  return result;
}

