// fwstruct annotate: 10dba4_sub_10DBA4.c
// sub_10DBA4 @ 0x10dba4, size 16 bytes
int __fastcall sub_10DBA4(char a1)
{
  int result; // r0

  result = (1 << a1) | *(_DWORD *)off_10DBB4;
  *(_DWORD *)off_10DBB4 = result;
  return result;
}

