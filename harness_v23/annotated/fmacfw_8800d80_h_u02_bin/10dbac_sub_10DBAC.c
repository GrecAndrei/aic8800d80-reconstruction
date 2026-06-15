// v23 annotated: sub_10DBAC @ 0x10dbac
// Original: 10dbac_sub_10DBAC.c
// Primary struct: <unclustered>
//
// sub_10DBAC @ 0x10dbac, size 16 bytes
int __fastcall sub_10DBAC(char a1)
{
  int result; // r0

  result = (1 << a1) | *((_DWORD *)off_10DBBC + 2);
  *((_DWORD *)off_10DBBC + 2) = result;
  return result;
}

