// v23 annotated: sub_10D654 @ 0x10d654
// Original: 10d654_sub_10D654.c
// Primary struct: <unclustered>
//
// sub_10D654 @ 0x10d654, size 34 bytes
_BYTE *__fastcall sub_10D654(_BYTE *result)
{
  int v1; // r1
  _DWORD *v2; // r2
  _DWORD *v3; // r4
  int v4; // t1

  v1 = (unsigned __int8)*result;
  if ( *result )
  {
    v2 = off_10D678;
    v3 = off_10D67C;
    do
    {
      while ( (*v2 & 0x80000) != 0 )
        ;
      *v3 = v1;
      v4 = (unsigned __int8)*++result;
      v1 = v4;
    }
    while ( v4 );
  }
  return result;
}

