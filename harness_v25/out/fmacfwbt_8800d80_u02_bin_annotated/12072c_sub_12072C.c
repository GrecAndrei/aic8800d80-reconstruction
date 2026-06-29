// fwstruct annotate: 12072c_sub_12072C.c
// sub_12072C @ 0x12072c, size 30 bytes
int sub_12072C()
{
  int result; // r0

  if ( *((unsigned __int8 *)off_12074C + 18) + *((unsigned __int8 *)off_12074C + 17) != 1 )
    return 0;
  result = *((_DWORD *)off_12074C + 2);
  if ( *(_BYTE *)(result + 106) )
    return 0;
  return result;
}

