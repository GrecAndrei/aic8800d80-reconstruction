// v23 annotated: sub_111218 @ 0x111218
// Original: 111218_sub_111218.c
// Primary struct: <unclustered>
//
// sub_111218 @ 0x111218, size 74 bytes
// Doc: rf_bus_mark_nbc [rf]: Marks RF bus registers at 0x900-0x914 with flags
// rf_bus_mark_nbc [rf]: Marks RF bus registers at 0x900-0x914 with flags
int sub_111218()
{
  _DWORD *v0; // r1
  int v1; // r0
  _DWORD *v2; // r3
  int result; // r0

  v0 = *(_DWORD **)rf_bus_write2_n_2c0;
  v1 = *(_DWORD *)rf_bus_write_268;
  v2 = rf_bus_write_n_200;
  *((_WORD *)rf_bus_reset2_n_94 + 5) = 0;
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

