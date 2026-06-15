// v23 annotated: hw_event_flag @ 0x111a04
// Original: 111a04_hw_event_flag.c
// Primary struct: <unclustered>
//
// hw_event_flag @ 0x111a04, size 32 bytes
// Doc: rf_bus_write2_n4f8 [rf]: Write to RF bus register with mode check
// rf_bus_write2_n4f8 [rf]: Write to RF bus register with mode check
int __fastcall hw_event_flag(int a1)
{
  int result; // r0
  int v2; // r3

  result = 32 * a1 + 1075838976;
  v2 = *(_DWORD *)(result + 2816);
  if ( v2 < 0 )
    *(_DWORD *)(result + 2816) = v2 & 0x7BFFFFFF | 0x4000000;
  return result;
}

