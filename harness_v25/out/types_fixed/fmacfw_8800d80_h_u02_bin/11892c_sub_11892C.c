// sub_11892C @ 0x11892c, size 58 bytes
int __fastcall sub_11892C(int a1, int a2, _DWORD *a3, int *a4)
{
  int v8; // r1
  int v9; // r2

  sub_100200((int *)a1, 0, 0x64u);
  *(_BYTE *)(a1 + 96) = 1;
  v8 = dword_118968;
  v9 = dword_11896C;
  *(_DWORD *)(a1 + 72) = a2;
  *(_DWORD *)(a1 + 44) = a4;
  *(_DWORD *)(a1 + 76) = a3;
  *(_DWORD *)(a3 + 0x34) = 0;
  *(_DWORD *)(a3 + 0x38) = 0;
  *(_DWORD *)(a3 + 0x1c) = a2 + 108;
  *(_DWORD *)(a3 + 0xc) = v8;
  *(_DWORD *)(a3 + 0x28) = 0;
  *(_DWORD *)(a3 + 0x3c) = 0;
  *a4 = v9;
  return a2 + 108;
}

