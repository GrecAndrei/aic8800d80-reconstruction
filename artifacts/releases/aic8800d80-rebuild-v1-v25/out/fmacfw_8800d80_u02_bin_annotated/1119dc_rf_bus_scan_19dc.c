// fwstruct annotate: 1119dc_rf_bus_scan_19dc.c
// rf_bus_scan_19dc @ 0x1119dc, size 30 bytes
// Doc: rf_bus_scan_19dc [rf]: Scans RF bus indices invoking sub_121196c per slot
// rf_bus_scan_19dc [rf]: Scans RF bus indices invoking sub_121196c per slot
int *rf_bus_scan_19dc()
{
  int i; // r4
  int v1; // r0
  int *result; // r0
  int v3; // [sp+4h] [bp-4h]

  for ( i = 1; i != 6; ++i )
  {
    v1 = (unsigned __int8)i;
    v3 = (unsigned __int8)i;
    sub_11196C(v1);
    result = rf_bus_write_9a4(v3);
  }
  return result;
}

