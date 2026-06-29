// fwstruct annotate: 125a98_sub_125A98.c
// sub_125A98 @ 0x125a98, size 18 bytes
int __fastcall sub_125A98(int a1)
{
  _BYTE *v1; // r3
  int v2; // r2

  v1 = off_125AAC;
  v2 = *((_DWORD *)off_125AAC + 1);
  *(_DWORD *)off_125AAC = a1;
  if ( !v2 )
    return sub_125A44(a1);
  v1[10] = 1;
  return a1;
}

