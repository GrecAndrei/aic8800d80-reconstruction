// rf_fault_dump_n4b0 @ 0x114bf8, size 42 bytes
// Doc: rf_fault_dump_n4c2 [rf]: Dump RF fault status and write flag to MMIO register
// rf_fault_dump_n4c2 [rf]: Dump RF fault status and write flag to MMIO register
void rf_fault_dump_n4b0()
{
  int *v0; // r4

  v0 = (int *)rf_fault_dump_n4dc;
  if ( !*(uint32_t *)rf_fault_dump_n4dc )
    *v0 = sub_114BB8();
  if ( !*(uint32_t *)patch_apply_n_284 )
    *(uint32_t *)patch_apply_n_284 = *v0 + 67092480;
  *(uint32_t *)off_114C2C = 1;
}

