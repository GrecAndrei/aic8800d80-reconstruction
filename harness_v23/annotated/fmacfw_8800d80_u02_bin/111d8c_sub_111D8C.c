// v23 annotated: sub_111D8C @ 0x111d8c
// Original: 111d8c_sub_111D8C.c
// Primary struct: tx_pkt_buf (cluster 7, 6 funcs)
// Fields: addr=0x0, len=0x4, ctrl=0x8, bssid=0xe, payload_end=0x320
//
// sub_111D8C @ 0x111d8c, size 40 bytes
// Doc: rf_bus_write_d94 [rf]: Write value to RF bus with type dispatch
// rf_bus_write_d94 [rf]: Write value to RF bus with type dispatch
int *__fastcall sub_111D8C(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)rf_bus_write2_1c1c(a2, 0x8000000, 0x200000);
  }
  else if ( a2 <= 5 )
  {
    return rf_bus_write_1b64(a2, 0x8000000, 0x200000);
  }
  return result;
}

