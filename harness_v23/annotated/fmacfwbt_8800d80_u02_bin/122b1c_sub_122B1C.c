// v23 annotated: sub_122B1C @ 0x122b1c
// Original: 122b1c_sub_122B1C.c
// Primary struct: phy_reg_param (cluster 12, 6 funcs)
// Fields: addr=0x0, status=0x6a
//
// sub_122B1C @ 0x122b1c, size 66 bytes
int sub_122B1C()
{
  int *v0; // r2
  int result; // r0
  _DWORD *v2; // r3

  v0 = *((int **)off_122B60 + 2);
  if ( v0 )
  {
    result = 0;
    while ( !*((_BYTE *)v0 + 106) )
    {
      if ( *((_BYTE *)v0 + 108) && (v2 = (_DWORD *)v0[60]) != nullptr )
      {
        do
        {
          v2 = (_DWORD *)*v2;
          if ( *((unsigned __int8 *)v0 + 116) != 255 )
            result = (unsigned __int8)(result + 1);
        }
        while ( v2 );
        v0 = (int *)*v0;
        if ( !v0 )
          return result;
      }
      else
      {
        v0 = (int *)*v0;
        if ( !v0 )
          return result;
      }
    }
  }
  return 0;
}

