// sub_10CEF4 @ 0x10cef4, size 44 bytes
int sub_10CEF4()
{
  uint32_t *v0; // r4
  int result; // r0

  v0 = off_10CF20;
  while ( !*(uint32_t *)off_10CF20 )
    ;
  result = *(uint32_t *)(*(uint32_t *)off_10CF24 + 532);
  if ( result )
  {
    result = sub_11E7AC(*(uint32_t *)off_10CF24 + 532);
    *v0 = 1;
    if ( result )
      result += 4;
  }
  else
  {
    *(uint32_t *)off_10CF20 = 1;
  }
  return result;
}

