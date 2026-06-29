// fwstruct annotate: 111bd0_sub_111BD0.c
// sub_111BD0 @ 0x111bd0, size 42 bytes
int __fastcall sub_111BD0(int a1, int a2)
{
  _DWORD *v2; // r0
  int v4; // r0

  if ( a2 )
  {
    if ( a1 == 1 )
      v4 = dword_111BFC;
    else
      v4 = dword_111C00;
    return (*(_DWORD *)(v4 + 32 * a2) >> 21) & 1;
  }
  else
  {
    if ( a1 == 1 )
      v2 = (_DWORD *)dword_111BFC;
    else
      v2 = (_DWORD *)dword_111C00;
    return (*v2 >> 21) & 1;
  }
}

