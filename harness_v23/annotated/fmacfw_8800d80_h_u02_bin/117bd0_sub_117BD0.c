// v23 annotated: sub_117BD0 @ 0x117bd0
// Original: 117bd0_sub_117BD0.c
// Primary struct: <unclustered>
//
// sub_117BD0 @ 0x117bd0, size 30 bytes
BOOL __fastcall sub_117BD0(int a1, int a2)
{
  unsigned int v2; // r3
  unsigned int v3; // r0

  v2 = *(unsigned __int16 *)(a1 + 32);
  v3 = *(unsigned __int16 *)(a2 + 32);
  if ( v2 > v3 )
    return 0;
  if ( v2 >= v3 )
    return 1;
  return (int)(v3 - v2) <= 63;
}

