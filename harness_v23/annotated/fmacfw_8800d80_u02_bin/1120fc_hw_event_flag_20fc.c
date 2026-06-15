// v23 annotated: hw_event_flag_20fc @ 0x1120fc
// Original: 1120fc_hw_event_flag_20fc.c
// Primary struct: <unclustered>
//
// hw_event_flag_20fc @ 0x1120fc, size 32 bytes
// Doc: rf_bus_init_n34e [rf]: Initializes RF bus interface for N3/E4 subsystem
// rf_bus_init_n34e [rf]: Initializes RF bus interface for N3/E4 subsystem
int __fastcall hw_event_flag_20fc(int a1)
{
  int result; // r0
  int v2; // r3

  result = 32 * a1 + 1075838976;
  v2 = *(_DWORD *)(result + 2816);
  if ( v2 < 0 )
    *(_DWORD *)(result + 2816) = v2 & 0x7BFFFFFF | 0x4000000;
  return result;
}

