// fwstruct annotate: 122a08_sub_122A08.c
// sub_122A08 @ 0x122a08, size 28 bytes
int __fastcall sub_122A08(int a1, _DWORD *a2, int a3, int a4)
{
  int v4; // r0
  _DWORD *v5; // r5
  int v6; // r4
  int v7; // r1

  v4 = *a2;
  v5 = a2;
  v6 = dword_122A24;
  v7 = a2[1];
  LOWORD(v5) = *((_WORD *)v5 + 4);
  *(_DWORD *)dword_122A24 = v4;
  *(_DWORD *)(v6 + 4) = v7;
  *(_WORD *)(v6 + 8) = (_WORD)v5;
  sub_12C8D0(138, a4, a3);
  return 0;
}

