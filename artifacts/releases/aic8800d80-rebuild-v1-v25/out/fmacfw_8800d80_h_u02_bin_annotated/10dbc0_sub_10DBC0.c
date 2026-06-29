// fwstruct annotate: 10dbc0_sub_10DBC0.c
// sub_10DBC0 @ 0x10dbc0, size 16 bytes
int __fastcall sub_10DBC0(char a1)
{
  int result; // r0

  result = (1 << a1) | *(_DWORD *)off_10DBD0;
  *(_DWORD *)off_10DBD0 = result;
  return result;
}

