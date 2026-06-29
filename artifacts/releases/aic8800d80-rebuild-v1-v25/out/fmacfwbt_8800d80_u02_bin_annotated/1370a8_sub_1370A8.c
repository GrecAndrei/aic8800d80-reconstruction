// fwstruct annotate: 1370a8_sub_1370A8.c
// sub_1370A8 @ 0x1370a8, size 64 bytes
int __fastcall sub_1370A8(int a1, unsigned __int16 *a2, int a3, __int16 a4)
{
  _BYTE *v5; // r4
  char *v6; // r0
  int v7; // r2

  v5 = (_BYTE *)rf_bus_setup_n3a8(4104, a4, 4, 2u);
  feature_guard_sdio(8, dword_1370E8);
  v6 = (char *)off_1370EC;
  v7 = *a2;
  *(_WORD *)off_1370EC = v7;
  sub_14380C(v6 + 3, (char *)a2 + 3, v7);
  *v5 = 1;
  v5[1] = *((_BYTE *)a2 + 2);
  sub_12CBB4((int)v5);
  return 0;
}

