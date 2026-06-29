// rf_bus_reset_n_90 @ 0x1146dc, size 14 bytes
// Doc: rf_bus_reset_n_90 [rf]: RF bus reset byte readback
// rf_bus_reset_n_90 [rf]: RF bus reset byte readback
void rf_bus_reset_n_90()
{
  *(uint32_t *)(*(uint32_t *)rf_fault_dump_n_5b + 8) |= 2u;
}

