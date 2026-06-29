// fwstruct annotate: 141484_sub_141484.c
// sub_141484 @ 0x141484, size 88 bytes
_DWORD *sub_141484()
{
  int v0; // r3
  int v1; // r0
  int v2; // r4
  _DWORD *result; // r0

  v0 = dword_1414DC;
  v1 = *(_DWORD *)(dword_1414DC + 6480) + 1;
  *(_DWORD *)(dword_1414DC + 6480) = v1;
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
    result = sub_12CD34(0xBu, 0);
    *(_DWORD *)(v2 + 144) = -1;
  }
  else
  {
    sub_12CD34(0xBu, 4);
    return (_DWORD *)sub_12CA10(11264, 11, 11);
  }
  return result;
}

