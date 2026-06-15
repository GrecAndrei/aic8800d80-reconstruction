// v23 annotated: sub_101F70 @ 0x101f70
// Original: 101f70_sub_101F70.c
// Primary struct: mmio_clock_gate (cluster 1, 21 funcs)
// Fields: reg_addr=0x0, bit_idx=0x0, mask=0x18, value=0x1c
//
// sub_101F70 @ 0x101f70, size 2412 bytes
void __fastcall __noreturn sub_101F70(int a1, int a2, int a3, int a4)
{
  msg_parse(dword_1022BC, dword_1022B8, a1);
  if ( **(_BYTE **)off_1022C0 != 3 )
    feature_guard_check(4, dword_1022C4);
  variant_update_cache(a4);
  rf_cmd_queue_next_n_d4();
}

