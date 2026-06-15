// sub_137000 @ 0x137000, size 32 bytes
// Doc: sub_1237000 [ipc]: IPC/control message handler entry
// sub_1237000 [ipc]: IPC/control message handler entry
int __fastcall sub_137000(int a1, int a2, int a3, __int16 a4)
{
  int v4; // r0

  v4 = rf_bus_setup_n3a8(4107, a4, 4, 1u);
  sub_12CBB4(v4);
  feature_guard_sdio(8, dword_137020);
  return 0;
}

