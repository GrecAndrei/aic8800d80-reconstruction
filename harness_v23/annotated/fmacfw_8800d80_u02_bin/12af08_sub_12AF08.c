// v23 annotated: sub_12AF08 @ 0x12af08
// Original: 12af08_sub_12AF08.c
// Primary struct: <unclustered>
//
// sub_12AF08 @ 0x12af08, size 30 bytes
// Doc: sub_122AF08 [unknown]: Unknown FMAC helper (no clear pattern)
// sub_122AF08 [unknown]: Unknown FMAC helper (no clear pattern)
int __fastcall sub_12AF08(int a1, int a2, int a3)
{
  int v3; // r3
  unsigned int v4; // r2
  int result; // r0

  v3 = dword_12AF28;
  v4 = (unsigned int)(1967 * a2 * a3) >> 16;
  result = dword_12AF28 + 32 * a1;
  if ( v4 )
    *(_DWORD *)(result + 24) = v4;
  else
    v3 = 1;
  if ( !v4 )
    *(_DWORD *)(result + 24) = v3;
  return result;
}

