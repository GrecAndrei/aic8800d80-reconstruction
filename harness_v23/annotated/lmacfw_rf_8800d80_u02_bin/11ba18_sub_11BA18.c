// v23 annotated: sub_11BA18 @ 0x11ba18
// Original: 11ba18_sub_11BA18.c
// Primary struct: <unclustered>
//
// sub_11BA18 @ 0x11ba18, size 44 bytes
int __fastcall sub_11BA18(int result)
{
  char v1; // r3
  void *v2; // r2

  if ( *((_BYTE *)off_11BA44 + 89) )
  {
    v1 = *((_BYTE *)off_11BA44 + 89) - 1;
    *((_BYTE *)off_11BA44 + 89) = v1;
    if ( !v1 )
    {
      v2 = off_11BA48;
      if ( *(_BYTE *)off_11BA48 == 1 )
      {
        *(_BYTE *)off_11BA48 = 0;
        rf_link_state_check(result, 1, (int)v2);
        return sub_11B9E0();
      }
    }
  }
  return result;
}

