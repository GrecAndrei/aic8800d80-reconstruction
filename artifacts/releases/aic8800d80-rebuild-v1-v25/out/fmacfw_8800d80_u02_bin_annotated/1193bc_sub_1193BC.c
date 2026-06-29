// fwstruct annotate: 1193bc_sub_1193BC.c
// sub_1193BC @ 0x1193bc, size 126 bytes
// Doc: sub_12193BC [unknown]: Unknown helper, no clear naming cues
// sub_12193BC [unknown]: Unknown helper, no clear naming cues
int __fastcall sub_1193BC(int a1, __int16 a2, int a3, __int16 a4, unsigned __int8 a5)
{
  int *v5; // r7
  int v6; // r6
  int v7; // r4
  int v8; // t1
  __int16 v9; // r12
  int v11; // r0
  int v12; // r4
  int v13; // r6
  int result; // r0

  v5 = (int *)off_119444;
  v6 = dword_11943C + 696 * a3;
  v7 = dword_119440 + 1320 * *(unsigned __int8 *)(v6 + 34);
  v8 = *(_DWORD *)(v6 + 38);
  v9 = *(_WORD *)(v7 + 104);
  v11 = *(_DWORD *)(v7 + 100);
  *(_WORD *)(a1 + 160) = *(_WORD *)(v6 + 42);
  *(_DWORD *)(a1 + 120) = a1 + 172;
  *(_DWORD *)(a1 + 88) = 0;
  *(_DWORD *)(a1 + 144) = 0;
  v12 = *v5;
  v13 = *v5;
  *(_DWORD *)(a1 + 162) = v11;
  result = (a5 << 7) | 0x808;
  *(_DWORD *)(a1 + 156) = v8;
  *(_DWORD *)(a1 + 208) = (unsigned __int16)((_WORD)v12 << 8) | (unsigned __int8)v13;
  *(_WORD *)(a1 + 166) = v9;
  *(_WORD *)(a1 + 168) = (a4 << 12) | 4;
  *(_WORD *)(a1 + 170) = 16 * a2;
  *(_DWORD *)(a1 + 192) = result;
  return result;
}

