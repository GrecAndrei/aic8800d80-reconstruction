// v23 annotated: sub_119308 @ 0x119308
// Original: 119308_sub_119308.c
// Primary struct: <unclustered>
//
// sub_119308 @ 0x119308, size 80 bytes
__int16 *__fastcall sub_119308(__int16 *result)
{
  int v1; // r2
  int v2; // r1
  _DWORD *v3; // r4
  int v4; // r3

  v1 = *((_DWORD *)result + 19);
  if ( *(_DWORD *)(v1 + 28) )
  {
    v2 = *((_DWORD *)off_119358 + 43);
    v3 = result;
    result = *(__int16 **)off_11935C;
    do
    {
      v4 = v3[9] & 0x380000;
      *(_DWORD *)(*(_DWORD *)(v1 + 32) - 3) = v2;
      if ( v4 == 3670016 )
        break;
      v3 = (_DWORD *)*v3;
      if ( *result < 0 && !v3 )
      {
        sub_12F32C(dword_119364, dword_119360, 909);
        __und(0xFFu);
      }
      v1 = v3[19];
    }
    while ( *(_DWORD *)(v1 + 28) );
  }
  return result;
}

