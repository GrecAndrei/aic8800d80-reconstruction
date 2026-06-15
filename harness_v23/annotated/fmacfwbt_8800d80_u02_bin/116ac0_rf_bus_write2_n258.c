// v23 annotated: rf_bus_write2_n258 @ 0x116ac0
// Original: 116ac0_rf_bus_write2_n258.c
// Primary struct: <unclustered>
//
// rf_bus_write2_n258 @ 0x116ac0, size 48 bytes
// Doc: rf_bus_write2_n258 [mmio]: Write 32-bit value to RF bus MMIO
// rf_bus_write2_n258 [mmio]: Write 32-bit value to RF bus MMIO
int __fastcall rf_bus_write2_n258(_BYTE *a1, char a2)
{
  int v2; // r6
  int v4; // r5

  v2 = dword_116AF0;
  v4 = 696 * (unsigned __int8)a1[29];
  a1[27] = a2;
  a1[97] = 1;
  list_push_tail(v4 + 572 + v2);
  return sub_136C94(a1, v2 + v4);
}

