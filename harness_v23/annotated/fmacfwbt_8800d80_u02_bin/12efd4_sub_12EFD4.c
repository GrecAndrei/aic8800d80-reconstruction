// v23 annotated: sub_12EFD4 @ 0x12efd4
// Original: 12efd4_sub_12EFD4.c
// Primary struct: <unclustered>
//
// sub_12EFD4 @ 0x12efd4, size 30 bytes
int __fastcall sub_12EFD4(int a1, int a2, __int16 a3, __int16 a4)
{
  _DWORD *v4; // r0

  v4 = (_DWORD *)rf_bus_setup_n3a8(1034, a4, a3, 0xCu);
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  sub_12CBB4((int)v4);
  return 0;
}

