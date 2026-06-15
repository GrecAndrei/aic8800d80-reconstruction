// sub_13BE40 @ 0x13be40, size 96 bytes
int __fastcall sub_13BE40(bool a1, int a2)
{
  unsigned int v2; // r5
  bool *v5; // r4
  int v6; // r1
  int v7; // r3

  v2 = (unsigned __int16)((_WORD)a2 << 8) | 8;
  v5 = (bool *)rf_bus_setup_n3a8(42, 0, ((_WORD)a2 << 8) | 8, 3u);
  if ( **(__int16 **)off_13BEA0 < 0 && msg_get_value(v2) != 4 )
    sub_12F694(dword_13BEAC, dword_13BEA8, 891);
  v6 = dword_13BEA4 + 32 * a2;
  v7 = *(unsigned __int8 *)(v6 + 17);
  v5[1] = a1;
  *v5 = v7 != 1;
  v5[2] = *(_BYTE *)(v6 + 22);
  return sub_12CBB4((int)v5);
}

