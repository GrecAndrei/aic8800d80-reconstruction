// v23 annotated: rf_bus_reset2_n_ec @ 0x11176c
// Original: 11176c_rf_bus_reset2_n_ec.c
// Primary struct: <unclustered>
//
// rf_bus_reset2_n_ec @ 0x11176c, size 74 bytes
// Doc: rf_bus_mark_na6 [rf]: Set RF bus bitfield (mask 0x7E0, value 0x20) on reg 0x10
// rf_bus_mark_na6 [rf]: Set RF bus bitfield (mask 0x7E0, value 0x20) on reg 0x10
int rf_bus_reset2_n_ec()
{
  _DWORD *v0; // r1
  int v1; // r0
  _DWORD *v2; // r3
  int result; // r0

  v0 = *(_DWORD **)rf_bus_write_n_208;
  v1 = *(_DWORD *)rf_bus_write2_n_2bc;
  v2 = rf_bus_reset2_n_98;
  *((_WORD *)rf_bus_write2_n_2b4 + 5) = 0;
  *v0 = 167772160;
  v0[1] = v1;
  v2[4] = v2[4] & 0xFFFFF81F | 0x20;
  do
    result = v2[4] & 0x20;
  while ( result );
  v2[578] = v2[578];
  v2[581] = v0;
  v2[576] |= 0x84000000;
  return result;
}

