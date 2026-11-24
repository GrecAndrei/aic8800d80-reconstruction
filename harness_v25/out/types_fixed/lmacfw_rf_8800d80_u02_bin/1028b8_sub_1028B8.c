// sub_1028B8 @ 0x1028b8, size 66 bytes
void __fastcall sub_1028B8(int *a1)
{
  int *v2; // r6
  int v3; // r7
  int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int v8; // r1
  int v9; // r2
  int v10; // r3

  sub_100A14();
  mmio_set_bit_120090C(0, 0x96Cu);
  sub_102828();
  v2 = (int *)off_102900;
  v3 = dword_102904;
  *(_DWORD *)off_1028FC &= 0xFFFFFC00;
  v4 = *a1;
  v5 = *(_DWORD *)(a1 + 0x4);
  v6 = *(_DWORD *)(a1 + 0x8);
  v7 = *(_DWORD *)(a1 + 0xc);
  a1 += 4;
  *v2 = v4;
  *(_DWORD *)(v2 + 0x4) = v5;
  *(_DWORD *)(v2 + 0x8) = v6;
  *(_DWORD *)(v2 + 0xc) = v7;
  v8 = *(_DWORD *)(a1 + 0x4);
  v9 = *(_DWORD *)(a1 + 0x8);
  v10 = *(_DWORD *)(a1 + 0xc);
  *(_DWORD *)(v2 + 0x10) = *a1;
  *(_DWORD *)(v2 + 0x14) = v8;
  *(_DWORD *)(v2 + 0x18) = v9;
  *(_DWORD *)(v2 + 0x1c) = v10;
  *(_DWORD *)(v2 + 0x20) = *(_DWORD *)(a1 + 0x10);
  *(_DWORD *)(v2 + 0x24) = v3;
  *(_DWORD *)(v2 + 0x28) = 16711935;
}

