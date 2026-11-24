// sub_141344 @ 0x141344, size 88 bytes
_DWORD *sub_141344()
{
  int v0; // r3
  int v1; // r0
  int v2; // r4
  _DWORD *result; // r0

  v0 = dword_14139C;
  v1 = *(_DWORD *)(dword_14139C + 6480) + 1;
  *(_DWORD *)(dword_14139C + 6480) = v1;
  v2 = v0;
  do
  {
    if ( *(unsigned __int16 *)(v2 + 4) > 1u )
      *(_WORD *)(v2 + 4) = 1;
    v2 += 528;
  }
  while ( v2 != v0 + 6336 );
  if ( v1 >= *(_DWORD *)(v2 + 148) )
  {
    result = sub_12CBF4(0xBu, 0);
    *(_DWORD *)(v2 + 144) = -1;
  }
  else
  {
    sub_12CBF4(0xBu, 4);
    return (_DWORD *)sub_12C8D0(11264, 11, 11);
  }
  return result;
}

