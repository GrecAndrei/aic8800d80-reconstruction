// fwstruct annotate: 109120_sub_109120.c
// sub_109120 @ 0x109120, size 114 bytes
_DWORD *__fastcall sub_109120(_DWORD *result, unsigned int *a2)
{
  int v2; // r3
  int v3; // r3
  int v4; // r3
  int v5; // r3
  int v6; // r2
  int v7; // r3
  unsigned int v8; // r3

  LOWORD(v2) = 50;
  do
    v2 = (unsigned __int16)(v2 - 1);
  while ( v2 );
  *(_DWORD *)off_109194 = 2;
  LOWORD(v3) = 50;
  do
    v3 = (unsigned __int16)(v3 - 1);
  while ( v3 );
  if ( (*(_DWORD *)off_109198 & 1) == 0 )
  {
    while ( 1 )
    {
      LOWORD(v4) = 50;
      do
        v4 = (unsigned __int16)(v4 - 1);
      while ( v4 );
      if ( (*(_DWORD *)off_109198 & 1) != 0 )
      {
        LOWORD(v5) = 50;
        do
          v5 = (unsigned __int16)(v5 - 1);
        while ( v5 );
        if ( (*(_DWORD *)off_109198 & 1) != 0 )
          break;
      }
    }
  }
  v6 = *(_DWORD *)off_109198;
  v7 = *(_DWORD *)off_109198 >> 17;
  if ( *(int *)off_109198 < 0 )
    v7 = ~((unsigned int)~(v7 << 17) >> 17);
  *result = v7;
  v8 = (unsigned __int16)v6 >> 1;
  if ( (v6 & 0x8000) != 0 )
    v8 = ~(~(v8 << 17) >> 17);
  *a2 = v8;
  return result;
}

