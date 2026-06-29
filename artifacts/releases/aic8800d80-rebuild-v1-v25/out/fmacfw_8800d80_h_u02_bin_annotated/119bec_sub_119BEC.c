// fwstruct annotate: 119bec_sub_119BEC.c
// sub_119BEC @ 0x119bec, size 30 bytes
unsigned int __fastcall sub_119BEC(int a1, unsigned int a2)
{
  unsigned int v2; // r3

  v2 = (unsigned __int16)(((*(_WORD *)(a1 + 24) + 3) & 0xFFFC) + 4);
  if ( a2 <= v2 )
    return 0;
  else
    return ((unsigned int)(unsigned __int16)(a2 - v2) + 3) >> 2;
}

