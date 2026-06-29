// fwstruct annotate: 10e420_rf_mmio_reg_enable.c
// rf_mmio_reg_enable @ 0x10e420, size 130 bytes
// Doc: rf_mmio_reg_enable [mmio]: Writes 1 to MMIO reg 0x4010d004 to enable RF block
// rf_mmio_reg_enable [mmio]: Writes 1 to MMIO reg 0x4010d004 to enable RF block
int rf_mmio_reg_enable()
{
  _DWORD *v0; // r2
  __int64 v1; // r0
  __int64 v2; // r0
  __int64 v3; // r0
  int v4; // r0
  float v5; // r0
  __int64 v6; // r0
  __int64 v7; // r0
  __int64 v8; // r0
  __int64 v9; // r0
  __int64 v10; // r0
  int v11; // r0

  v0 = off_10E4C8;
  *((_DWORD *)off_10E4C8 + 1) = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = sub_12752C(v0[4]);
  v2 = sub_127620(v1, HIDWORD(v1), dword_10E4A8, dword_10E4AC);
  v3 = sub_127874(v2, HIDWORD(v2), dword_10E4B0, dword_10E4B4);
  v4 = sub_1272B0(v3, HIDWORD(v3), dword_10E4A8, dword_10E4AC);
  v5 = sub_127BE4(v4);
  v6 = sub_127570(LODWORD(v5));
  v7 = sub_127874(v6, HIDWORD(v6), dword_10E4B8, dword_10E4BC);
  v8 = sub_127620(v7, HIDWORD(v7), 0, dword_10E4CC);
  v9 = sub_127620(v8, HIDWORD(v8), 0, dword_10E4D0);
  v10 = sub_127620(v9, HIDWORD(v9), dword_10E4C0, dword_10E4C4);
  v11 = sub_127874(v10, HIDWORD(v10), 0, dword_10E4D4);
  return (int)sub_127BE4(v11);
}

