// v23 annotated: rf_init_setup_n3ac @ 0x10fe5c
// Original: 10fe5c_rf_init_setup_n3ac.c
// Primary struct: <unclustered>
//
// rf_init_setup_n3ac @ 0x10fe5c, size 66 bytes
// Doc: rf_init_setup_n3ac [rf]: Initialize RF subsystem registers from arguments
// rf_init_setup_n3ac [rf]: Initialize RF subsystem registers from arguments
int __fastcall rf_init_setup_n3ac(int a1, int a2, int a3)
{
  _DWORD *v3; // r3
  _DWORD *v4; // r3

  v3 = off_10FEA0;
  *((_DWORD *)off_10FEA0 + 3) = dword_10FEA4;
  *v3 = a2;
  v3[1] = a3;
  *((_BYTE *)v3 + 8) = 4;
  sub_10F814(v3, a1, 0x20u);
  v4 = off_10FEA8;
  *((_DWORD *)off_10FEA8 + 5) = 4;
  v4[1] = 0x10000;
  v4[3] = 131074;
  v4[6] = 0x40000;
  *v4 = 1;
  v4[2] = 1;
  v4[4] = 0;
  *((_WORD *)v4 + 14) = 0;
  return 0x40000;
}

