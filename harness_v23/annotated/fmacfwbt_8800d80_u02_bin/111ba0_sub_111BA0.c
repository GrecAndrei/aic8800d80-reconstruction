// v23 annotated: sub_111BA0 @ 0x111ba0
// Original: 111ba0_sub_111BA0.c
// Primary struct: tx_pkt_buf (cluster 6, 6 funcs)
// Fields: addr=0x0, len=0x4, ctrl=0x8, bssid=0xe, payload_end=0x320
//
// sub_111BA0 @ 0x111ba0, size 36 bytes
// Doc: rf_bus_write2_n12e [rf]: RF bus write variant dispatch on parameter
// rf_bus_write2_n12e [rf]: RF bus write variant dispatch on parameter
int *__fastcall sub_111BA0(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)rf_bus_write2_1a78(a2, 0x8000000, 0);
  }
  else if ( a2 <= 5 )
  {
    return sub_1119C0(a2, 0x8000000, 0);
  }
  return result;
}

