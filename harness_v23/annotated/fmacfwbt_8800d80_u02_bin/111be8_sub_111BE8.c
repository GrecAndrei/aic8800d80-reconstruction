// v23 annotated: sub_111BE8 @ 0x111be8
// Original: 111be8_sub_111BE8.c
// Primary struct: tx_pkt_buf (cluster 6, 6 funcs)
// Fields: addr=0x0, len=0x4, ctrl=0x8, bssid=0xe, payload_end=0x320
//
// sub_111BE8 @ 0x111be8, size 40 bytes
// Doc: rf_bus_setup_n_15a [rf]: Configure RF bus interface
// rf_bus_setup_n_15a [rf]: Configure RF bus interface
int *__fastcall sub_111BE8(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)rf_bus_write2_1a78(a2, 0x8000000, 0x200000);
  }
  else if ( a2 <= 5 )
  {
    return sub_1119C0(a2, 0x8000000, 0x200000);
  }
  return result;
}

