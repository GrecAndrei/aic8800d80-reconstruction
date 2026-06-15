// rf_mem_write_nf0 @ 0x12211c, size 108 bytes
// Doc: rf_mem_write [mmio]: Write 32-bit value to RF memory-mapped register
// rf_mem_write [mmio]: Write 32-bit value to RF memory-mapped register
int __fastcall rf_mem_write_nf0(int a1, int a2)
{
  int v3; // r5
  int v4; // r4
  int v5; // r0
  _DWORD *v6; // r3

  if ( a1 <= 2 )
  {
    v4 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0x10u);
    msg_parse(dword_122188, v4);
    goto rf_cmd_dispatch_n240;
  }
  v3 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0);
  v4 = parse_int(*(unsigned __int8 **)(a2 + 8), nullptr, 0x10u);
  msg_parse(dword_122188, v4);
  if ( v3 == 1 )
rf_cmd_dispatch_n240:
    v4 = *(_DWORD *)(v4 + 4);
  v5 = msg_parse(dword_12218C, v4);
  v6 = rf_mem_write_block;
  *((_DWORD *)rf_cmd_dispatch_190 + 65) = 8;
  v6[2] &= ~0x20000u;
  v6[2] |= 0x40000u;
  ((void (__fastcall *)(int))v4)(v5);
  return 0;
}

