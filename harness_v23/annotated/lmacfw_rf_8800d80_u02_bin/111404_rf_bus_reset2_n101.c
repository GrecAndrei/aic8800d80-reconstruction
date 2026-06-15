// v23 annotated: rf_bus_reset2_n101 @ 0x111404
// Original: 111404_rf_bus_reset2_n101.c
// Primary struct: <unclustered>
//
// rf_bus_reset2_n101 @ 0x111404, size 88 bytes
// Doc: rf_bus_setup_n_3ef [rf]: RF bus setup writing 32-bit/16-bit MMIO fields
// rf_bus_setup_n_3ef [rf]: RF bus setup writing 32-bit/16-bit MMIO fields
int __fastcall rf_bus_reset2_n101(int result, int a2)
{
  int *v2; // r4
  int v3; // r5
  int v4; // r3
  char v5; // r2
  _DWORD *v6; // r2

  v2 = (int *)rf_bus_mark_n2d4;
  v3 = *(_DWORD *)off_11145C;
  v4 = *(_DWORD *)rf_bus_mark_n2d4;
  *((_WORD *)rf_bus_write2_n_c0 + 5) = a2;
  if ( a2 == 64 )
    v5 = -54;
  else
    v5 = -50;
  *(_DWORD *)v4 = -1073741824;
  *(_DWORD *)(v4 + 4) = v3;
  *(_BYTE *)(v4 + 3) = v5;
  *(_WORD *)v4 = a2;
  if ( result && a2 )
  {
    result = sub_1282E8(v3, result, a2);
    v4 = *v2;
  }
  v6 = rf_bus_write2_n_bc;
  *(_BYTE *)(v4 + 3) &= 0x3Fu;
  v6[578] = v6[578];
  v6[581] = v4;
  v6[576] |= 0x84000000;
  return result;
}

