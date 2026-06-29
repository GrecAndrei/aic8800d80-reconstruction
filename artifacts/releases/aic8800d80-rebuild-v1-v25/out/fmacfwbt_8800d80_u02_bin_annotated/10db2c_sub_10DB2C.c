// fwstruct annotate: 10db2c_sub_10DB2C.c
// sub_10DB2C @ 0x10db2c, size 18 bytes
int __fastcall sub_10DB2C(char a1)
{
  int result; // r0

  result = 1 << a1;
  *((_DWORD *)off_10DB40 + 2) &= ~result;
  return result;
}

