// sub_128BB0 @ 0x128bb0, size 96 bytes
unsigned __int16 * sub_128BB0(int a1, int a2)
{
  unsigned __int16 *result; // r0
  int *i; // r3
  int v6; // r3

  sub_12EB90(2, dword_128C14);
  result = (unsigned __int16 *)sub_1289EC(a1, a2, dword_128C18);
  if ( result )
  {
    result = (unsigned __int16 *)off_128C1C;
    if ( !*((uint8_t *)off_128C1C + 8)
      || (v6 = (unsigned __int8)(*((uint8_t *)off_128C1C + 8) - 1), *((uint8_t *)off_128C1C + 8) = v6, !v6) )
    {
      for ( i = *((int **)off_128C20 + 2); i; i = (int *)*i )
      {
        if ( !*((uint8_t *)i + 106) )
        {
          if ( *((uint8_t *)i + 108) )
            i[1] &= 0xFFFFFFF1;
        }
      }
      *(uint8_t *)result = 0;
      return (unsigned __int16 *)sub_12C8D0(50, result[1], 0);
    }
  }
  return result;
}

