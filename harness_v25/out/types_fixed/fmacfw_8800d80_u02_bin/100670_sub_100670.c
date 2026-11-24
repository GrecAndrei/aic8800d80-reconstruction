// sub_100670 @ 0x100670, size 18 bytes
int __fastcall sub_100670(int a1)
{
  int result; // r0

  result = sub_1005B0(a1);
  if ( *(unsigned __int8 *)off_100684 != result )
    *(_BYTE *)off_100684 = result;
  return result;
}

