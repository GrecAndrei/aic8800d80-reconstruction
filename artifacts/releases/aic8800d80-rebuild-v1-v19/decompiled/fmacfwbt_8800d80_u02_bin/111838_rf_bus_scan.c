// rf_bus_scan @ 0x111838, size 30 bytes
// Doc: rf_bus_write2_n_234 [mmio]: Tail of RF bus write helper, restore frame and return
// rf_bus_write2_n_234 [mmio]: Tail of RF bus write helper, restore frame and return
int *rf_bus_scan()
{
  int i; // r4
  int v1; // r0
  int *result; // r0
  int v3; // [sp+4h] [bp-4h]

  for ( i = 1; i != 6; ++i )
  {
    v1 = (unsigned __int8)i;
    v3 = (unsigned __int8)i;
    sub_1117C8(v1);
    result = rf_bus_write_n_1c0(v3);
  }
  return result;
}

