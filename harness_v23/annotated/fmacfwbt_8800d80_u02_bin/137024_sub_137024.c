// v23 annotated: sub_137024 @ 0x137024
// Original: 137024_sub_137024.c
// Primary struct: <unclustered>
//
// sub_137024 @ 0x137024, size 40 bytes
// Doc: sub_1237024 [scan]: Scan channel 11 with bandwidth setting
// sub_1237024 [scan]: Scan channel 11 with bandwidth setting
int sub_137024()
{
  unsigned __int16 *v0; // r4
  int v1; // r0

  v0 = (unsigned __int16 *)off_13704C;
  v1 = rf_bus_setup_n3a8(4107, *((_WORD *)off_13704C + 1924), 4, 1u);
  sub_12CBB4(v1);
  feature_guard_sdio(8, dword_137050, v0[1924]);
  return 0;
}

