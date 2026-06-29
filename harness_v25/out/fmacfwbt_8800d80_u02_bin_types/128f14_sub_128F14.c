// sub_128F14 @ 0x128f14, size 96 bytes
unsigned __int16 * sub_128F14(int a1, int a2, int a3, int a4)
{
  unsigned __int16 *result; // r0
  int *i; // r3
  int v8; // r3

  feature_guard_sdio(2, dword_128F78);
  result = (unsigned __int16 *)sub_128D50(a1, a2, dword_128F7C);
  if ( result )
  {
    result = (unsigned __int16 *)off_128F80;
    if ( !*((uint8_t *)off_128F80 + 8)
      || (v8 = (unsigned __int8)(*((uint8_t *)off_128F80 + 8) - 1), *((uint8_t *)off_128F80 + 8) = v8, !v8) )
    {
      for ( i = *((int **)off_128F84 + 2); i; i = (int *)*i )
      {
        if ( !*((uint8_t *)i + 106) )
        {
          if ( *((uint8_t *)i + 108) )
            i[1] &= 0xFFFFFFF1;
        }
      }
      *(uint8_t *)result = 0;
      return (unsigned __int16 *)message_dispatch_n84(50, result[1], 0, a4);
    }
  }
  return result;
}

