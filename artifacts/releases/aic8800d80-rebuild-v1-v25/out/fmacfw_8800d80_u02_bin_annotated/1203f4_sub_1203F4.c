// fwstruct annotate: 1203f4_sub_1203F4.c
// sub_1203F4 @ 0x1203f4, size 30 bytes
int sub_1203F4()
{
  int result; // r0

  if ( *((unsigned __int8 *)off_120414 + 18) + *((unsigned __int8 *)off_120414 + 17) != 1 )
    return 0;
  result = *((_DWORD *)off_120414 + 2);
  if ( *(_BYTE *)(result + 106) )
    return 0;
  return result;
}

