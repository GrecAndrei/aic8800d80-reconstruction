// sub_10058C @ 0x10058c, size 18 bytes
int  sub_10058C(int a1)
{
  int result; // r0

  result = sub_1004CC(a1);
  if ( *(unsigned __int8 *)off_1005A0 != result )
    *(uint8_t *)off_1005A0 = result;
  return result;
}

