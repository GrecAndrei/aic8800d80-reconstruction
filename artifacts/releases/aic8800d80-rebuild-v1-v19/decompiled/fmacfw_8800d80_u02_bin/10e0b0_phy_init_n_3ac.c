// phy_init_n_3ac @ 0x10e0b0, size 252 bytes
// Doc: phy_init_n_3ac [mmio]: Initialize PHY/MMIO block at 0x4010d000 with enable
// phy_init_n_3ac [mmio]: Initialize PHY/MMIO block at 0x4010d000 with enable
int phy_init_n_3ac()
{
  _DWORD *v0; // r5
  __int64 v1; // r0
  __int64 v2; // r0
  __int64 v3; // r0
  int v4; // r0
  int v5; // r6
  _DWORD *v6; // r2
  int v7; // r4
  __int64 v8; // r0
  __int64 v9; // r0
  __int64 v10; // r0
  int v11; // r0
  int v12; // r0
  __int64 v13; // r0
  __int64 v14; // r0
  __int64 v15; // r4
  __int64 v16; // r0
  __int64 v17; // r0
  __int64 v18; // r0
  __int64 v19; // r0
  __int64 v20; // r0
  __int64 v21; // r0
  int v22; // r0

  v0 = off_10E1D0;
  mmio_field_update(1);
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = sub_1429B4(v0[4]);
  v2 = sub_142AA8(v1, HIDWORD(v1), dword_10E1B0, dword_10E1B4);
  v3 = sub_142CFC(v2, HIDWORD(v2), dword_10E1B8, dword_10E1BC);
  v4 = sub_142738(v3, HIDWORD(v3), dword_10E1B0, dword_10E1B4);
  v5 = ((int (__fastcall *)(int))sub_14306C)(v4);
  mmio_field_update(2);
  v6 = off_10E1D0;
  v0[1] = 1;
  while ( v6[7] != 1 )
    ;
  v6[7] = 1;
  v7 = v6[4];
  mmio_field_update(3);
  v8 = sub_1429B4(v7);
  v9 = sub_142AA8(v8, HIDWORD(v8), dword_10E1B0, dword_10E1B4);
  v10 = sub_142CFC(v9, HIDWORD(v9), dword_10E1B8, dword_10E1BC);
  v11 = sub_142738(v10, HIDWORD(v10), dword_10E1B0, dword_10E1B4);
  v12 = ((int (__fastcall *)(int))sub_14306C)(v11);
  v13 = sub_1429F8(v12);
  v14 = sub_142CFC(v13, HIDWORD(v13), dword_10E1C0, dword_10E1C4);
  v15 = sub_142AA8(v14, HIDWORD(v14), 0, dword_10E1D4);
  v16 = sub_1429F8(v5);
  v17 = sub_142CFC(v16, HIDWORD(v16), dword_10E1C0, dword_10E1C4);
  v18 = sub_142AA8(v17, HIDWORD(v17), 0, dword_10E1D8);
  v19 = sub_14273C(v15, HIDWORD(v15), v18, HIDWORD(v18));
  v20 = sub_142AA8(v19, HIDWORD(v19), 0, dword_10E1DC);
  v21 = sub_142AA8(v20, HIDWORD(v20), dword_10E1C8, dword_10E1CC);
  v22 = sub_142CFC(v21, HIDWORD(v21), 0, dword_10E1E0);
  return (int)sub_14306C(v22);
}

