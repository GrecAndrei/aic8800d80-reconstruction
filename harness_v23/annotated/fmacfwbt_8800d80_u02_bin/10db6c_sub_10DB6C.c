// v23 annotated: sub_10DB6C @ 0x10db6c
// Original: 10db6c_sub_10DB6C.c
// Primary struct: <unclustered>
//
// sub_10DB6C @ 0x10db6c, size 18 bytes
int __fastcall sub_10DB6C(char a1)
{
  int result; // r0

  result = 1 << a1;
  *(_DWORD *)off_10DB80 &= ~result;
  return result;
}

