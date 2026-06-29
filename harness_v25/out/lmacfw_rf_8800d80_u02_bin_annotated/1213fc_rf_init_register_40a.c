// fwstruct annotate: 1213fc_rf_init_register_40a.c
// rf_init_register_40a @ 0x1213fc, size 30 bytes
// Doc: rf_init_register_40a [rf]: Initialize RF register block 0x40a and clear state
// rf_init_register_40a [rf]: Initialize RF register block 0x40a and clear state
int __fastcall rf_init_register_40a(int a1, int a2, __int16 a3, __int16 a4)
{
  _DWORD *v4; // r0

  v4 = (_DWORD *)rf_setup_dispatch(1034, a4, a3, 0xCu);
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  sub_11DE50((int)v4);
  return 0;
}

