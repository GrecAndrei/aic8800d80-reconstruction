// fwstruct annotate: 116490_sub_116490.c
// sub_116490 @ 0x116490, size 56 bytes
int __fastcall sub_116490(int a1)
{
  int v1; // r1
  int v2; // r3
  int result; // r0

  v1 = dword_1164C8;
  v2 = dword_1164C8 + 36 * a1;
  *(_DWORD *)v2 = 0;
  result = v1 + 8 * (a1 + 22);
  *(_DWORD *)(v2 + 8) = 4978;
  *(_DWORD *)(v2 + 12) = -1;
  *(_DWORD *)(result + 4) = 0;
  *(_DWORD *)(result + 8) = 0;
  *(_DWORD *)(v2 + 4) = 0;
  *(_BYTE *)(v2 + 32) = 0;
  *(_DWORD *)(v2 + 20) = 0;
  *(_DWORD *)(v2 + 16) = -1;
  return result;
}

