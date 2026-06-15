// sub_128BB0 @ 0x128bb0, size 96 bytes
unsigned __int16 *__fastcall sub_128BB0(int a1, int a2)
{
  unsigned __int16 *result; // r0
  int *i; // r3
  int v6; // r3

  sub_12EB90(2, dword_128C14);
  result = (unsigned __int16 *)sub_1289EC(a1, a2, dword_128C18);
  if ( result )
  {
    result = (unsigned __int16 *)off_128C1C;
    if ( !*((_BYTE *)off_128C1C + 8)
      || (v6 = (unsigned __int8)(*((_BYTE *)off_128C1C + 8) - 1), *((_BYTE *)off_128C1C + 8) = v6, !v6) )
    {
      for ( i = *((int **)off_128C20 + 2); i; i = (int *)*i )
      {
        if ( !*((_BYTE *)i + 106) )
        {
          if ( *((_BYTE *)i + 108) )
            i[1] &= 0xFFFFFFF1;
        }
      }
      *(_BYTE *)result = 0;
      return (unsigned __int16 *)sub_12C8D0(50, result[1], 0);
    }
  }
  return result;
}

