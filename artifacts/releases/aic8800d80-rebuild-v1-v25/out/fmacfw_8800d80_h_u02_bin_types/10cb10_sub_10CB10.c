// sub_10CB10 @ 0x10cb10, size 44 bytes
int sub_10CB10()
{
  uint32_t *v0; // r4
  int result; // r0

  v0 = off_10CB3C;
  while ( !*(uint32_t *)off_10CB3C )
    ;
  result = *(uint32_t *)(*(uint32_t *)off_10CB40 + 596);
  if ( result )
  {
    result = sub_12D190(*(uint32_t *)off_10CB40 + 596);
    *v0 = 1;
    if ( result )
      result += 4;
  }
  else
  {
    *(uint32_t *)off_10CB3C = 1;
  }
  return result;
}

