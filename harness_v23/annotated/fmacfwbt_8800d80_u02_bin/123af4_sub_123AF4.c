// v23 annotated: sub_123AF4 @ 0x123af4
// Original: 123af4_sub_123AF4.c
// Primary struct: <unclustered>
//
// sub_123AF4 @ 0x123af4, size 60 bytes
int __fastcall sub_123AF4(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v4; // r5
  int v6; // r0
  int v7; // r4

  v4 = dword_123B30 + 1320 * *a2;
  v6 = rf_bus_setup_n3a8(47, a4, a3, 2);
  *(_BYTE *)(v4 + 110) = a2[1];
  v7 = v6;
  message_dispatch_c7ac(v4);
  message_dispatch_n_4c4(v4, v7 + 1, v7);
  sub_12CBB4(v7);
  return 0;
}

