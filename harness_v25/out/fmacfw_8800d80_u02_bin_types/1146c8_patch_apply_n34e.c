// patch_apply_n34e @ 0x1146c8, size 14 bytes
// Doc: rf_fault_dump_n7a [rf]: Clears fault bit and prepares RF fault dump buffer
// rf_fault_dump_n7a [rf]: Clears fault bit and prepares RF fault dump buffer
void patch_apply_n34e()
{
  *(uint32_t *)(*(uint32_t *)msg_dispatch + 8) &= ~2u;
}

