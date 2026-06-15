// rf_fault_dump_n4b0 @ 0x114bf8, size 42 bytes
// Doc: rf_fault_dump_n4c2 [rf]: Dump RF fault status and write flag to MMIO register
// rf_fault_dump_n4c2 [rf]: Dump RF fault status and write flag to MMIO register
void rf_fault_dump_n4b0()
{
  int *v0; // r4

  v0 = (int *)rf_fault_dump_n4dc;
  if ( !*(_DWORD *)rf_fault_dump_n4dc )
    *v0 = sub_114BB8();
  if ( !*(_DWORD *)patch_apply_n_284 )
    *(_DWORD *)patch_apply_n_284 = *v0 + 67092480;
  *(_DWORD *)off_114C2C = 1;
}

