// v23 annotated: sub_128CF0 @ 0x128cf0
// Original: 128cf0_sub_128CF0.c
// Primary struct: <unclustered>
//
// sub_128CF0 @ 0x128cf0, size 96 bytes
unsigned __int16 *__fastcall sub_128CF0(int a1, int a2)
{
  unsigned __int16 *result; // r0
  int *i; // r3
  int v6; // r3

  feature_guard_check(2, dword_128D54);
  result = (unsigned __int16 *)sub_128B2C(a1, a2, dword_128D58);
  if ( result )
  {
    result = (unsigned __int16 *)off_128D5C;
    if ( !*((_BYTE *)off_128D5C + 8)
      || (v6 = (unsigned __int8)(*((_BYTE *)off_128D5C + 8) - 1), *((_BYTE *)off_128D5C + 8) = v6, !v6) )
    {
      for ( i = *((int **)off_128D60 + 2); i; i = (int *)*i )
      {
        if ( !*((_BYTE *)i + 106) )
        {
          if ( *((_BYTE *)i + 108) )
            i[1] &= 0xFFFFFFF1;
        }
      }
      *(_BYTE *)result = 0;
      return (unsigned __int16 *)sub_12CA10(50, result[1], 0);
    }
  }
  return result;
}

