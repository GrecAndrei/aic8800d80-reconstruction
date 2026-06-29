// fwstruct annotate: 101f70_sub_101F70.c
// sub_101F70 @ 0x101f70, size 2412 bytes
void __fastcall __noreturn sub_101F70(int a1, int a2, int a3, int a4)
{
  msg_parse(dword_1022BC, dword_1022B8, a1);
  if ( **(_BYTE **)off_1022C0 != 3 )
    feature_guard_check(4, dword_1022C4);
  variant_update_cache(a4);
  rf_cmd_queue_next_n_d4();
}

