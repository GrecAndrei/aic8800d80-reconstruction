// fwstruct annotate: 1152d8_sub_1152D8.c
// sub_1152D8 @ 0x1152d8, size 56 bytes
__int64 __fastcall sub_1152D8(int a1)
{
  int v1; // r1
  int v2; // r3
  int v3; // r5
  int v4; // r0
  int v5; // r3
  int v6; // r4

  v1 = dword_115310;
  v2 = 9 * a1;
  v3 = 36 * a1;
  v4 = a1 + 18;
  v5 = dword_115310 + 4 * v2;
  v6 = dword_115310 + 8 * v4;
  *(_DWORD *)(dword_115310 + v3) = 0;
  *(_DWORD *)(v1 + 8 * v4) = 0;
  *(_DWORD *)(v6 + 4) = 0;
  *(_QWORD *)(v5 + 8) = -4294966370LL;
  *(_DWORD *)(v5 + 4) = 0;
  *(_BYTE *)(v5 + 32) = 0;
  *(_DWORD *)(v5 + 20) = 0;
  *(_DWORD *)(v5 + 16) = -1;
  return -4294966370LL;
}

