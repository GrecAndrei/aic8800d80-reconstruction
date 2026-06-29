// fwstruct annotate: 1227a8_sub_1227A8.c
// sub_1227A8 @ 0x1227a8, size 66 bytes
int sub_1227A8()
{
  int *v0; // r2
  int result; // r0
  _DWORD *v2; // r3

  v0 = *((int **)off_1227EC + 2);
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

