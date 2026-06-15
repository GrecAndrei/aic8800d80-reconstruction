// v23 annotated: sub_129C60 @ 0x129c60
// Original: 129c60_sub_129C60.c
// Primary struct: <unclustered>
//
// sub_129C60 @ 0x129c60, size 56 bytes
unsigned __int8 *__fastcall sub_129C60(unsigned __int8 *result)
{
  int v1; // r3
  unsigned __int8 *v2; // r4
  int v3; // r1

  v1 = result[114];
  v2 = result;
  if ( v1 == 1 )
  {
    result[114] = 0;
    return sub_129804(result);
  }
  else if ( v1 == 2 )
  {
    v3 = *((_DWORD *)result + 29);
    result[114] = 1;
    timestamp_update((int)(result + 96), v3);
    return sub_129804(v2);
  }
  return result;
}

