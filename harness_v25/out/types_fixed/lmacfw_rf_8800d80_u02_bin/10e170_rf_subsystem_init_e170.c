// rf_subsystem_init_e170 @ 0x10e170, size 138 bytes
// Doc: rf_subsystem_init_e170 [mmio]: Initialize RF subsystem MMIO at 0x4010d000/0x40100000
// rf_subsystem_init_e170 [mmio]: Initialize RF subsystem MMIO at 0x4010d000/0x40100000
float rf_subsystem_init_e170()
{
  _DWORD *v0; // r4
  _DWORD *v1; // r2
  int v2; // r3
  int v3; // r0
  int v4; // r1
  unsigned int v5; // r4

  v0 = off_10E1FC;
  v1 = off_10E200;
  v2 = dword_10E204;
  v3 = dword_10E208;
  v4 = dword_10E20C;
  *(_DWORD *)off_10E1FC = 0;
  *(_DWORD *)(v1 + 0x38) = 296;
  *(_DWORD *)(v0 + 0x8) = *(_DWORD *)(v0 + 0x8) & 0xF000FFFF | 0x2000000;
  *(_DWORD *)(v0 + 0xc) = v2 & *(_DWORD *)(v0 + 0xc) | 0xA06A000;
  *(_DWORD *)(v0 + 0xc) = v4 | v3 & *(_DWORD *)(v0 + 0xc);
  rf_pll_ldo_init();
  *(_DWORD *)(v0 + 0x4) = 1;
  while ( *(_DWORD *)(v0 + 0x1c) != 1 )
    ;
  *(_DWORD *)(v0 + 0x1c) = 1;
  v5 = *(_DWORD *)(v0 + 0x10);
  rf_reg_write_cb(dword_10E210, 0, 15360);
  return (float)((float)((float)v5 / flt_10E214) - 1.0) * flt_10E218;
}

