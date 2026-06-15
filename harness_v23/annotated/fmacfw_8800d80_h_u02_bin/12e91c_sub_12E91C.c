// v23 annotated: sub_12E91C @ 0x12e91c
// Original: 12e91c_sub_12E91C.c
// Primary struct: delay_timer (cluster 0, 24 funcs)
// Fields: us=0x0, ticks=0x4
//
// sub_12E91C @ 0x12e91c, size 40 bytes
BOOL __fastcall sub_12E91C(unsigned int a1, unsigned int a2)
{
  BOOL result; // r0

  if ( a1 > 9 )
    return 0;
  result = (*(_DWORD *)off_12E944 >> a1) & 1;
  if ( result )
    return *((_DWORD *)off_12E944 + 1) >= a2;
  return result;
}

