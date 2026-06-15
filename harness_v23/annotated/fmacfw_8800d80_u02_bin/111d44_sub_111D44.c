// v23 annotated: sub_111D44 @ 0x111d44
// Original: 111d44_sub_111D44.c
// Primary struct: tx_pkt_buf (cluster 7, 6 funcs)
// Fields: addr=0x0, len=0x4, ctrl=0x8, bssid=0xe, payload_end=0x320
//
// sub_111D44 @ 0x111d44, size 36 bytes
// Doc: rf_bus_reset2_n35f [rf]: Stub returning immediately (bx lr) for RF bus reset variant
// rf_bus_reset2_n35f [rf]: Stub returning immediately (bx lr) for RF bus reset variant
int *__fastcall sub_111D44(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)rf_bus_write2_1c1c(a2, 0x8000000, 0);
  }
  else if ( a2 <= 5 )
  {
    return rf_bus_write_1b64(a2, 0x8000000, 0);
  }
  return result;
}

