// v23 annotated: rf_flag_clear_n_90 @ 0x1146b8
// Original: 1146b8_rf_flag_clear_n_90.c
// Primary struct: rf_state (cluster 8, 4 funcs)
// Fields: flags=0x0, sub_flag0=0x6, sub_flag1=0x9, sub_flag2=0xb, value=0xc, cfg=0x58
//
// rf_flag_clear_n_90 @ 0x1146b8, size 10 bytes
// Doc: rf_flag_clear_n_90 [rf]: Clear a global RF status flag by zeroing word
// rf_flag_clear_n_90 [rf]: Clear a global RF status flag by zeroing word
void rf_flag_clear_n_90()
{
  **(_DWORD **)rf_fault_dump_n_84 = **(_DWORD **)rf_fault_dump_n_84;
}

