// sub_1202B4 @ 0x1202b4, size 30 bytes
int sub_1202B4()
{
  int result; // r0

  if ( *((unsigned __int8 *)off_1202D4 + 18) + *((unsigned __int8 *)off_1202D4 + 17) != 1 )
    return 0;
  result = *((uint32_t *)off_1202D4 + 2);
  if ( *(uint8_t *)(result + 106) )
    return 0;
  return result;
}

