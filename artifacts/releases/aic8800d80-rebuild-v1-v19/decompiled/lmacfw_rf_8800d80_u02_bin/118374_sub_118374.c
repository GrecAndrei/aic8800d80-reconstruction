// sub_118374 @ 0x118374, size 38 bytes
int __fastcall sub_118374(_BYTE *a1)
{
  _DWORD *v1; // r3
  int *v2; // r3
  int result; // r0

  v1 = off_11839C;
  *a1 = 0;
  v2 = (int *)v1[2];
  if ( !v2 )
    return 0;
  result = 0;
  do
  {
    if ( !*((_BYTE *)v2 + 94) )
    {
      if ( *((_BYTE *)v2 + 96) )
        ++result;
    }
    v2 = (int *)*v2;
  }
  while ( v2 );
  return result;
}

