// fwstruct annotate: 118c90_sub_118C90.c
// sub_118C90 @ 0x118c90, size 114 bytes
unsigned int __fastcall sub_118C90(unsigned int result)
{
  int v1; // r3
  _DWORD *v2; // r1
  _DWORD *v3; // r2
  _DWORD *v4; // r2
  unsigned int *v5; // r1
  _DWORD *v6; // r5
  _DWORD *v7; // r4

  if ( result <= 0xF )
  {
    v3 = off_118D10;
    *(_DWORD *)off_118D0C = -1;
    *v3 = -1;
  }
  else
  {
    v1 = dword_118D04 + 152 * (unsigned __int8)(result - 16);
    if ( *(_BYTE *)(dword_118D08 + 224 * *(unsigned __int8 *)(v1 + 32) + 94) == 2 )
      return result;
    v2 = off_118D10;
    *(_DWORD *)off_118D0C = *(unsigned __int16 *)(v1 + 36) | (*(unsigned __int16 *)(v1 + 38) << 16);
    *v2 = *(unsigned __int16 *)(v1 + 40);
  }
  v4 = off_118D14;
  v5 = (unsigned int *)off_118D18;
  v6 = off_118D20;
  v7 = off_118D24;
  result = (result << 16) | 0x40000000;
  *(_DWORD *)off_118D1C = 0;
  *v6 = 0;
  *v4 = 0;
  *v7 = 0;
  *v5 = result;
  while ( (*v5 & 0x40000000) != 0 )
    ;
  return result;
}

