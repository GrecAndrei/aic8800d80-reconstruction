// v23 annotated: sub_10D60C @ 0x10d60c
// Original: 10d60c_sub_10D60C.c
// Primary struct: <unclustered>
//
// sub_10D60C @ 0x10d60c, size 34 bytes
_BYTE *__fastcall sub_10D60C(_BYTE *result)
{
  int v1; // r1
  _DWORD *v2; // r2
  _DWORD *v3; // r4
  int v4; // t1

  v1 = (unsigned __int8)*result;
  if ( *result )
  {
    v2 = off_10D630;
    v3 = off_10D634;
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

