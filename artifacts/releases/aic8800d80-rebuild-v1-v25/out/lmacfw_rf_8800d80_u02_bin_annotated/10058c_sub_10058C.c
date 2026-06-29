// fwstruct annotate: 10058c_sub_10058C.c
// sub_10058C @ 0x10058c, size 18 bytes
int __fastcall sub_10058C(int a1)
{
  int result; // r0

  result = sub_1004CC(a1);
  if ( *(unsigned __int8 *)off_1005A0 != result )
    *(_BYTE *)off_1005A0 = result;
  return result;
}

