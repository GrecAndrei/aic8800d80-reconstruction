// fwstruct annotate: 115f60_sub_115F60.c
// sub_115F60 @ 0x115f60, size 34 bytes
int __fastcall sub_115F60(int a1, int a2)
{
  int v2; // r3
  int result; // r0
  int v4; // r2

  v2 = dword_115F84;
  result = a1 + 22;
  v4 = dword_115F84 + 8 * result;
  if ( *(_DWORD *)(v4 + 4) )
    v4 = *(_DWORD *)(v4 + 8);
  *(_DWORD *)(v4 + 4) = a2;
  *(_DWORD *)(v2 + 8 * result + 8) = a2;
  *(_DWORD *)(a2 + 4) = 0;
  return result;
}

