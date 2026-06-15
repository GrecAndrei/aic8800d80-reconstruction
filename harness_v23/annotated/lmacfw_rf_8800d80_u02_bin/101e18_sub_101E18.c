// v23 annotated: sub_101E18 @ 0x101e18
// Original: 101e18_sub_101E18.c
// Primary struct: mmio_clock_gate (cluster 1, 25 funcs)
// Fields: reg_addr=0x0, bit_idx=0x0, mask=0x18, value=0x1c
//
// sub_101E18 @ 0x101e18, size 2476 bytes
void __fastcall __noreturn sub_101E18(int a1, int a2, int a3, int a4)
{
  msg_parse(dword_102164, dword_102160);
  if ( **(_BYTE **)off_102168 != 3 )
    msg_parse(dword_10216C, a3);
  sub_10058C(a4);
  rf_init_or_setup_n_1200a80();
}

