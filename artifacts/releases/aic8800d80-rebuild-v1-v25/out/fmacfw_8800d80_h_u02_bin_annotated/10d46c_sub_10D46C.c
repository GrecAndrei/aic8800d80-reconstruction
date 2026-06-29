// fwstruct annotate: 10d46c_sub_10D46C.c
// sub_10D46C @ 0x10d46c, size 36 bytes
int sub_10D46C()
{
  int v0; // r3
  int result; // r0

  v0 = *((_DWORD *)off_10D490 + 3);
  if ( (v0 & 0x8000) != 0 )
    *((_DWORD *)off_10D490 + 2) = 0x800000;
  if ( (v0 & 0x400) != 0 )
  {
    *((_DWORD *)off_10D490 + 2) = 0x40000;
    return sub_12CFC4(0x20000000);
  }
  return result;
}

