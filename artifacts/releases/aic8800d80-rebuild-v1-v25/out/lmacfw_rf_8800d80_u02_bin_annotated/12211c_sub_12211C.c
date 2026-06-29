// fwstruct annotate: 12211c_sub_12211C.c
// sub_12211C @ 0x12211c, size 108 bytes
int __fastcall sub_12211C(int a1, int a2)
{
  int v3; // r5
  int v4; // r4
  int v5; // r0
  _DWORD *v6; // r3

  if ( a1 <= 2 )
  {
    v4 = sub_121E3C(*(unsigned __int8 **)(a2 + 4), nullptr, 0x10u);
    sub_11F504(dword_122188, v4);
    goto LABEL_5;
  }
  v3 = sub_121E3C(*(unsigned __int8 **)(a2 + 4), nullptr, 0);
  v4 = sub_121E3C(*(unsigned __int8 **)(a2 + 8), nullptr, 0x10u);
  sub_11F504(dword_122188, v4);
  if ( v3 == 1 )
LABEL_5:
    v4 = *(_DWORD *)(v4 + 4);
  v5 = sub_11F504(dword_12218C, v4);
  v6 = off_122194;
  *((_DWORD *)off_122190 + 65) = 8;
  v6[2] &= ~0x20000u;
  v6[2] |= 0x40000u;
  ((void (__fastcall *)(int))v4)(v5);
  return 0;
}

