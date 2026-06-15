// v23 annotated: sub_111D68 @ 0x111d68
// Original: 111d68_sub_111D68.c
// Primary struct: tx_pkt_buf (cluster 7, 6 funcs)
// Fields: addr=0x0, len=0x4, ctrl=0x8, bssid=0xe, payload_end=0x320
//
// sub_111D68 @ 0x111d68, size 36 bytes
// Doc: rf_bus_write2_n162 [rf]: Trivial RF bus write2 stub (return only)
// rf_bus_write2_n162 [rf]: Trivial RF bus write2 stub (return only)
int *__fastcall sub_111D68(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)rf_bus_write2_1c1c(a2, 0x200000, 0);
  }
  else if ( a2 <= 5 )
  {
    return rf_bus_write_1b64(a2, 0x200000, 0);
  }
  return result;
}

