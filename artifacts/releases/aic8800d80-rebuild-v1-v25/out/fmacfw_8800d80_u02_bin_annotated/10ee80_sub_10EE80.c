// fwstruct annotate: 10ee80_sub_10EE80.c
// sub_10EE80 @ 0x10ee80, size 66 bytes
int __fastcall sub_10EE80(int a1, int a2, int a3)
{
  msg_parse(dword_10EEC4, a1, a3);
  sub_10EE2C(dword_10EECC, 196608, dword_10EEC8, 1);
  sub_10EE2C(1879048192, 1, 1, 1);
  rf_reg_write_wait(dword_10EED0, a1, 1);
  return sub_10EE2C(dword_10EED4, 2, 2, 1);
}

