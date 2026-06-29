// fwstruct annotate: 136ae8_sub_136AE8.c
// sub_136AE8 @ 0x136ae8, size 58 bytes
// Doc: sub_1236AE8 [bt]: Init/dispatch helper, calls 0x12cb54 with constants 0x3f/0/7/0xc
// sub_1236AE8 [bt]: Init/dispatch helper, calls 0x12cb54 with constants 0x3f/0/7/0xc
_DWORD *sub_136AE8()
{
  int v0; // r4
  int v1; // r0
  __int16 v2; // r1
  __int16 v3; // r2

  v0 = *(_DWORD *)off_136B24;
  v1 = rf_bus_setup_n3a8(63, 0, 7, 0xCu);
  v2 = *(_WORD *)(v0 + 36);
  v3 = *(_WORD *)(v0 + 38);
  *(_DWORD *)v1 = *(_DWORD *)(v0 + 32);
  *(_WORD *)(v1 + 4) = v2;
  *(_WORD *)(v1 + 6) = v3;
  *(_BYTE *)(v1 + 8) = *(_BYTE *)(v0 + 50);
  *(_BYTE *)(v1 + 9) = *(_BYTE *)(v0 + 51);
  sub_12CBB4(v1);
  return rf_bus_mark_n_3b7(7u, 2);
}

