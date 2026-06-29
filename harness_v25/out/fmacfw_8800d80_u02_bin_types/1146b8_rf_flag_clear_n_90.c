// rf_flag_clear_n_90 @ 0x1146b8, size 10 bytes
// Doc: rf_flag_clear_n_90 [rf]: Clear a global RF status flag by zeroing word
// rf_flag_clear_n_90 [rf]: Clear a global RF status flag by zeroing word
void rf_flag_clear_n_90()
{
  **(uint32_t **)rf_fault_dump_n_84 = **(uint32_t **)rf_fault_dump_n_84;
}

