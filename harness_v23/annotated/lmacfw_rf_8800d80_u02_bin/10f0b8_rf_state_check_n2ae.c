// v23 annotated: rf_state_check_n2ae @ 0x10f0b8
// Original: 10f0b8_rf_state_check_n2ae.c
// Primary struct: <unclustered>
//
// rf_state_check_n2ae @ 0x10f0b8, size 66 bytes
// Doc: rf_state_check_n2ae [rf]: Check RF state, store halfword and trigger 0x1119c0
// rf_state_check_n2ae [rf]: Check RF state, store halfword and trigger 0x1119c0
int __fastcall rf_state_check_n2ae(int a1)
{
  msg_parse(dword_10F0FC, a1);
  sub_10F064(dword_10F104, 196608, dword_10F100, 1);
  sub_10F064(1879048192, 1, 1, 1);
  rf_reg_write_wait(dword_10F108, a1, 1);
  return sub_10F064(dword_10F10C, 2, 2, 1);
}

