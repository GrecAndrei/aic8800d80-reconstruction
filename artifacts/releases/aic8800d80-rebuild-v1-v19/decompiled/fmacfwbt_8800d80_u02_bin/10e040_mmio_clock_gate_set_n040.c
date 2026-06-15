// mmio_clock_gate_set_n040 @ 0x10e040, size 130 bytes
// Doc: mmio_clock_gate_set_n040 [mmio]: Set MMIO clock gate enable bit at 0x4010d000+4
// mmio_clock_gate_set_n040 [mmio]: Set MMIO clock gate enable bit at 0x4010d000+4
int mmio_clock_gate_set_n040()
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

  v0 = off_10E0E8;
  *((_DWORD *)off_10E0E8 + 1) = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = sub_142A50(v0[4]);
  v2 = sub_142B44(v1, HIDWORD(v1), dword_10E0C8, dword_10E0CC);
  v3 = sub_142D98(v2, HIDWORD(v2), dword_10E0D0, dword_10E0D4);
  v4 = sub_1427D4(v3, HIDWORD(v3), dword_10E0C8, dword_10E0CC);
  v5 = sub_143108(v4);
  v6 = sub_142A94(LODWORD(v5));
  v7 = sub_142D98(v6, HIDWORD(v6), dword_10E0D8, dword_10E0DC);
  v8 = sub_142B44(v7, HIDWORD(v7), 0, dword_10E0EC);
  v9 = sub_142B44(v8, HIDWORD(v8), 0, dword_10E0F0);
  v10 = sub_142B44(v9, HIDWORD(v9), dword_10E0E0, dword_10E0E4);
  v11 = sub_142D98(v10, HIDWORD(v10), 0, dword_10E0F4);
  return (int)sub_143108(v11);
}

