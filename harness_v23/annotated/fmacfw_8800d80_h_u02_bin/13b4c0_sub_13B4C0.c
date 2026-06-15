// v23 annotated: sub_13B4C0 @ 0x13b4c0
// Original: 13b4c0_sub_13B4C0.c
// Primary struct: <unclustered>
//
// sub_13B4C0 @ 0x13b4c0, size 42 bytes
int __fastcall sub_13B4C0(int a1, int a2, unsigned int a3)
{
  int v4; // r0

  if ( sub_12CD48(a3) == 1 )
  {
    if ( a3 < 0x1000 )
      v4 = dword_13B4F4;
    else
      v4 = dword_13B4F0;
    sub_12D108(v4, (_DWORD *)(dword_13B4EC + 32 * (a3 >> 8)));
  }
  return 0;
}

