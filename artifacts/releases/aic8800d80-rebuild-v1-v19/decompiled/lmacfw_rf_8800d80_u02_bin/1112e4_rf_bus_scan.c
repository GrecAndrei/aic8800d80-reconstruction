// rf_bus_scan @ 0x1112e4, size 30 bytes
// Doc: rf_bus_write2_n_226 [rf]: Write to RF bus register with mask/set pattern
// rf_bus_write2_n_226 [rf]: Write to RF bus register with mask/set pattern
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
    rf_bus_mark_ne8(v1);
    result = sub_1112AC(v3);
  }
  return result;
}

