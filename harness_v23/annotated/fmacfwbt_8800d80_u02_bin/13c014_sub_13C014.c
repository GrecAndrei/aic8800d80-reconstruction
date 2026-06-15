// v23 annotated: sub_13C014 @ 0x13c014
// Original: 13c014_sub_13C014.c
// Primary struct: <unclustered>
//
// sub_13C014 @ 0x13c014, size 52 bytes
// Doc: sub_123C014 [util]: Loads pointer and dereferences offset 0x18
// sub_123C014 [util]: Loads pointer and dereferences offset 0x18
int sub_13C014()
{
  _DWORD *v0; // r4
  int result; // r0
  unsigned int v2; // r0

  v0 = off_13C048;
  if ( !*((_DWORD *)off_13C048 + 6)
    || (result = *((unsigned __int8 *)sub_12D4F8((int)off_13C048 + 24) + 26), result == 33) )
  {
    if ( v0[8] )
      return 33;
    v2 = (unsigned __int8)bt_dispatch_3arg((int **)dword_13C04C);
    if ( (unsigned __int8)v2 == 33 )
    {
      return 33;
    }
    else
    {
      sub_13BF94(v2);
      return 33;
    }
  }
  return result;
}

