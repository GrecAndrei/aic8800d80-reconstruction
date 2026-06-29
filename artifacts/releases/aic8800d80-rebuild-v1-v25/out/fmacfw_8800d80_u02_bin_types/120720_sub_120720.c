// sub_120720 @ 0x120720, size 88 bytes
uint32_t *sub_120720()
{
  uint8_t *v0; // r4
  int *v1; // r0
  int v2; // r0
  int v3; // r0
  int v4; // r0
  int v5; // r0
  int v6; // r0
  int v7; // r0
  int v8; // r0
  int v9; // r0

  v0 = off_120778;
  if ( !*((uint8_t *)off_120778 + 2) )
    sub_12B8BC();
  sub_120548();
  sub_11F724();
  v1 = sub_11EDF0();
  v2 = sub_12AE40(v1);
  v3 = sub_128EF8(v2);
  sub_129F44(v3);
  v4 = sub_116E7C();
  if ( v0[2] )
    v5 = nullsub_4(v4);
  else
    v5 = sub_11D7FC();
  v6 = sub_124D30(v5);
  v7 = sub_12B170(v6);
  v8 = sub_127A1C(v7);
  v9 = sub_12C33C(v8);
  sub_125734(v9);
  sub_10F25C();
  return sub_1205BC();
}

