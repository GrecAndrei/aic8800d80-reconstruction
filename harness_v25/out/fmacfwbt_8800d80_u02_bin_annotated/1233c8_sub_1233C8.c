// fwstruct annotate: 1233c8_sub_1233C8.c
// sub_1233C8 @ 0x1233c8, size 56 bytes
// Doc: sub_12233C8 [mac]: Sends 0x85 message and arms timer via 0x70000010 register
// sub_12233C8 [mac]: Sends 0x85 message and arms timer via 0x70000010 register
int __fastcall sub_1233C8(int a1, int a2, int a3, int a4)
{
  _BYTE *v4; // r4
  unsigned int v5; // r0

  v4 = (_BYTE *)rf_bus_setup_n3a8(133, a4, a3, 1);
  v5 = sub_10EBDC(dword_123400, 1);
  *v4 = (BYTE2(v5) ^ 1) & 1;
  sub_12ECB0(dword_123404, v5, HIWORD(v5) & 1);
  sub_12CBB4(v4);
  return 0;
}

