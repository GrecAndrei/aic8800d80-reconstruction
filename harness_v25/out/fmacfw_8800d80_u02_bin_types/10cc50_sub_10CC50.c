// sub_10CC50 @ 0x10cc50, size 44 bytes
int sub_10CC50()
{
  uint32_t *v0; // r4
  int result; // r0

  v0 = off_10CC7C;
  while ( !*(uint32_t *)off_10CC7C )
    ;
  result = *(uint32_t *)(*(uint32_t *)off_10CC80 + 596);
  if ( result )
  {
    result = rf_bus_mark_n100_d2d0(*(uint32_t *)off_10CC80 + 596);
    *v0 = 1;
    if ( result )
      result += 4;
  }
  else
  {
    *(uint32_t *)off_10CC7C = 1;
  }
  return result;
}

