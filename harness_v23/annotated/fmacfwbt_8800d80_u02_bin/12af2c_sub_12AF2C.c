// v23 annotated: sub_12AF2C @ 0x12af2c
// Original: 12af2c_sub_12AF2C.c
// Primary struct: <unclustered>
//
// sub_12AF2C @ 0x12af2c, size 22 bytes
int __fastcall sub_12AF2C(int result)
{
  if ( *(_BYTE *)(result + 1224) )
  {
    if ( *(_BYTE *)(result + 108) )
      *(_DWORD *)(result + 4) |= 0x40u;
  }
  return result;
}

