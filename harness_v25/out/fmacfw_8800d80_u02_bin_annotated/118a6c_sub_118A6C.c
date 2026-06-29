// fwstruct annotate: 118a6c_sub_118A6C.c
// sub_118A6C @ 0x118a6c, size 58 bytes
int __fastcall sub_118A6C(int a1, int a2, _DWORD *a3, int *a4)
{
  int v8; // r1
  int v9; // r2

  memset_thunk((int *)a1, 0, 0x64u);
  *(_BYTE *)(a1 + 96) = 1;
  v8 = dword_118AA8;
  v9 = dword_118AAC;
  *(_DWORD *)(a1 + 72) = a2;
  *(_DWORD *)(a1 + 44) = a4;
  *(_DWORD *)(a1 + 76) = a3;
  a3[13] = 0;
  a3[14] = 0;
  a3[7] = a2 + 108;
  a3[3] = v8;
  a3[10] = 0;
  a3[15] = 0;
  *a4 = v9;
  return a2 + 108;
}

