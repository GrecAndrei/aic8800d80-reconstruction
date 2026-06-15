// v23 annotated: sub_12F03C @ 0x12f03c
// Original: 12f03c_sub_12F03C.c
// Primary struct: <unclustered>
//
// sub_12F03C @ 0x12f03c, size 82 bytes
int __fastcall sub_12F03C(int a1, _DWORD *a2, __int16 a3, __int16 a4)
{
  _DWORD *v5; // r5
  int v6; // r0
  bool v7; // zf
  int v8; // r2

  v5 = (_DWORD *)rf_bus_setup_n3a8(1036, a4, a3, 4u);
  v6 = *a2;
  v7 = *a2 << 30 == 0;
  v8 = a2[1];
  *v5 = 0;
  if ( !v7 )
    *v5 = 255;
  if ( v8 << 30 )
    *v5 = 1;
  sub_14380C(v6, a2 + 2, v8);
  sub_12ECB0(dword_12F090, *a2, a2[1] + *a2, a2[2], *v5);
  sub_12CBB4((int)v5);
  return 0;
}

