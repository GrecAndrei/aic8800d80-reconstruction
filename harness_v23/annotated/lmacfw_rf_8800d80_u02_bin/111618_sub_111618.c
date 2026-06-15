// v23 annotated: sub_111618 @ 0x111618
// Original: 111618_sub_111618.c
// Primary struct: tx_pkt_buf (cluster 7, 6 funcs)
// Fields: addr=0x0, len=0x4, ctrl=0x8, bssid=0xe, payload_end=0x320
//
// sub_111618 @ 0x111618, size 42 bytes
// Doc: rf_fault_dump_n254 [rf]: Dump RF fault context by copying 12 bytes from fault record to stack
// rf_fault_dump_n254 [rf]: Dump RF fault context by copying 12 bytes from fault record to stack
int __fastcall sub_111618(int a1, int a2)
{
  _DWORD *v2; // r0
  int v4; // r0

  if ( a2 )
  {
    if ( a1 == 1 )
      v4 = dword_111644;
    else
      v4 = rf_bus_reset2_n344;
    return (*(_DWORD *)(v4 + 32 * a2) >> 21) & 1;
  }
  else
  {
    if ( a1 == 1 )
      v2 = (_DWORD *)dword_111644;
    else
      v2 = (_DWORD *)rf_bus_reset2_n344;
    return (*v2 >> 21) & 1;
  }
}

