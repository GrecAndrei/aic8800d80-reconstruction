// v23 annotated: sub_12EC84 @ 0x12ec84
// Original: 12ec84_sub_12EC84.c
// Primary struct: delay_timer (cluster 0, 25 funcs)
// Fields: us=0x0, ticks=0x4
//
// sub_12EC84 @ 0x12ec84, size 40 bytes
BOOL __fastcall sub_12EC84(unsigned int a1, unsigned int a2)
{
  BOOL result; // r0

  if ( a1 > 9 )
    return 0;
  result = (*(_DWORD *)off_12ECAC >> a1) & 1;
  if ( result )
    return *((_DWORD *)off_12ECAC + 1) >= a2;
  return result;
}

