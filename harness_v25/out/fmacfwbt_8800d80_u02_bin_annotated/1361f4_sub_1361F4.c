// fwstruct annotate: 1361f4_sub_1361F4.c
// sub_1361F4 @ 0x1361f4, size 68 bytes
int __fastcall sub_1361F4(int a1, unsigned __int8 *a2, __int16 a3, __int16 a4)
{
  unsigned __int16 v5; // r7
  _BYTE *v8; // r0

  v5 = *((_WORD *)a2 + 1);
  sub_14380C(dword_136238 + (*a2 << 9), a2 + 4, v5);
  *(_WORD *)(dword_13623C + 2 * *a2) = v5;
  v8 = (_BYTE *)rf_bus_setup_n3a8(7177, a4, a3, 2u);
  *v8 = 1;
  v8[1] = *a2;
  sub_12CBB4((int)v8);
  return 0;
}

