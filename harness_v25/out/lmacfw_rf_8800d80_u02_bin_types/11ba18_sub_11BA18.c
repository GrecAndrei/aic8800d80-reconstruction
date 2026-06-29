// sub_11BA18 @ 0x11ba18, size 44 bytes
int  sub_11BA18(int result)
{
  char v1; // r3
  void *v2; // r2

  if ( *((uint8_t *)off_11BA44 + 89) )
  {
    v1 = *((uint8_t *)off_11BA44 + 89) - 1;
    *((uint8_t *)off_11BA44 + 89) = v1;
    if ( !v1 )
    {
      v2 = off_11BA48;
      if ( *(uint8_t *)off_11BA48 == 1 )
      {
        *(uint8_t *)off_11BA48 = 0;
        rf_link_state_check(result, 1, (int)v2);
        return sub_11B9E0();
      }
    }
  }
  return result;
}

