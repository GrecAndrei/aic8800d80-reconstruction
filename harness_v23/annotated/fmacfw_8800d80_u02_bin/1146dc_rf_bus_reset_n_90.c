// v23 annotated: rf_bus_reset_n_90 @ 0x1146dc
// Original: 1146dc_rf_bus_reset_n_90.c
// Primary struct: rf_state (cluster 8, 4 funcs)
// Fields: flags=0x0, sub_flag0=0x6, sub_flag1=0x9, sub_flag2=0xb, value=0xc, cfg=0x58
//
// rf_bus_reset_n_90 @ 0x1146dc, size 14 bytes
// Doc: rf_bus_reset_n_90 [rf]: RF bus reset byte readback
// rf_bus_reset_n_90 [rf]: RF bus reset byte readback
void rf_bus_reset_n_90()
{
  *(_DWORD *)(*(_DWORD *)rf_fault_dump_n_5b + 8) |= 2u;
}

