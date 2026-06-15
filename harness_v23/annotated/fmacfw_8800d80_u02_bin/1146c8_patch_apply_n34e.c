// v23 annotated: patch_apply_n34e @ 0x1146c8
// Original: 1146c8_patch_apply_n34e.c
// Primary struct: rf_state (cluster 8, 4 funcs)
// Fields: flags=0x0, sub_flag0=0x6, sub_flag1=0x9, sub_flag2=0xb, value=0xc, cfg=0x58
//
// patch_apply_n34e @ 0x1146c8, size 14 bytes
// Doc: rf_fault_dump_n7a [rf]: Clears fault bit and prepares RF fault dump buffer
// rf_fault_dump_n7a [rf]: Clears fault bit and prepares RF fault dump buffer
void patch_apply_n34e()
{
  *(_DWORD *)(*(_DWORD *)msg_dispatch + 8) &= ~2u;
}

