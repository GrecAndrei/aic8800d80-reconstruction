// sub_10285C @ 0x10285c, size 52 bytes
// fmac_module_init [mac]: Initialize fmac module and dispatch to sub-init routine
void __fastcall fmac_module_init(int *a1)
{
  int v2; // r0
  int v3; // r1
  int v4; // r2
  int v5; // r3
  _DWORD *v6; // r6
  int v7; // r7
  int *v8; // r5
  int v9; // r1
  int v10; // r2
  int v11; // r3

  sub_100AA8();
  sub_1009A0(0, 0x96Cu);
  rf_bus_write2_n_3aa();
  v2 = *a1;
  v3 = *(_DWORD *)(a1 + 0x4);
  v4 = *(_DWORD *)(a1 + 0x8);
  v5 = *(_DWORD *)(a1 + 0xc);
  a1 += 4;
  v6 = off_102890;
  v7 = dword_102894;
  v8 = (int *)off_102890;
  *(_DWORD *)off_102890 = v2;
  *(_DWORD *)(v8 + 0x4) = v3;
  *(_DWORD *)(v8 + 0x8) = v4;
  *(_DWORD *)(v8 + 0xc) = v5;
  v8 += 4;
  v9 = *(_DWORD *)(a1 + 0x4);
  v10 = *(_DWORD *)(a1 + 0x8);
  v11 = *(_DWORD *)(a1 + 0xc);
  *v8 = *a1;
  *(_DWORD *)(v8 + 0x4) = v9;
  *(_DWORD *)(v8 + 0x8) = v10;
  *(_DWORD *)(v8 + 0xc) = v11;
  *(_DWORD *)(v8 + 0x10) = *(_DWORD *)(a1 + 0x10);
  *(_DWORD *)(v6 + 0x24) = v7;
  *(_DWORD *)(v6 + 0x28) = 16711935;
}

