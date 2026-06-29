// sub_111618 @ 0x111618, size 42 bytes
// Doc: rf_fault_dump_n254 [rf]: Dump RF fault context by copying 12 bytes from fault record to stack
// rf_fault_dump_n254 [rf]: Dump RF fault context by copying 12 bytes from fault record to stack
int  sub_111618(int a1, int a2)
{
  uint32_t *v2; // r0
  int v4; // r0

  if ( a2 )
  {
    if ( a1 == 1 )
      v4 = dword_111644;
    else
      v4 = rf_bus_reset2_n344;
    return (*(uint32_t *)(v4 + 32 * a2) >> 21) & 1;
  }
  else
  {
    if ( a1 == 1 )
      v2 = (uint32_t *)dword_111644;
    else
      v2 = (uint32_t *)rf_bus_reset2_n344;
    return (*v2 >> 21) & 1;
  }
}

