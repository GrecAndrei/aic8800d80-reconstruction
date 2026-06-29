// fwstruct annotate: 1202f8_sub_1202F8.c
// sub_1202F8 @ 0x1202f8, size 80 bytes
int __fastcall sub_1202F8(_BYTE *a1)
{
  _DWORD *v1; // r3
  int *v2; // r3
  int result; // r0

  v1 = off_120348;
  *a1 = 0;
  v2 = (int *)v1[2];
  if ( v2 )
  {
    result = 0;
    while ( 1 )
    {
      if ( *((_BYTE *)v2 + 106) )
      {
        if ( *((_BYTE *)v2 + 108) && *((_BYTE *)v2 + 1224) )
          goto LABEL_10;
LABEL_6:
        v2 = (int *)*v2;
        if ( !v2 )
          return result;
      }
      else
      {
        if ( !*((_BYTE *)v2 + 108) )
          goto LABEL_6;
        if ( !*((_BYTE *)v2 + 1224) )
        {
          ++result;
          goto LABEL_6;
        }
LABEL_10:
        *a1 = 1;
        v2 = (int *)*v2;
        if ( !v2 )
          return result;
      }
    }
  }
  return 0;
}

