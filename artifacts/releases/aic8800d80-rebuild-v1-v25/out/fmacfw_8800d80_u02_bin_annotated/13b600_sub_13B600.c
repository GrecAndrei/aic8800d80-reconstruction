// fwstruct annotate: 13b600_sub_13B600.c
// sub_13B600 @ 0x13b600, size 42 bytes
int __fastcall sub_13B600(int a1, int a2, unsigned int a3)
{
  int v4; // r0

  if ( sub_12CE88(a3) == 1 )
  {
    if ( a3 < 0x1000 )
      v4 = dword_13B634;
    else
      v4 = dword_13B630;
    sub_12D248(v4, (_DWORD *)(dword_13B62C + 32 * (a3 >> 8)));
  }
  return 0;
}

