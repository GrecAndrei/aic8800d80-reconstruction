// fwstruct annotate: 1146c8_patch_apply_n34e.c
// patch_apply_n34e @ 0x1146c8, size 14 bytes
// Doc: rf_fault_dump_n7a [rf]: Clears fault bit and prepares RF fault dump buffer
// rf_fault_dump_n7a [rf]: Clears fault bit and prepares RF fault dump buffer
void patch_apply_n34e()
{
  *(_DWORD *)(*(_DWORD *)msg_dispatch + 8) &= ~2u;
}

