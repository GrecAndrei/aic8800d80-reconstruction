// rf_hw_init_n008 @ 0x10e008, size 142 bytes
// Doc: rf_hw_init_n008 [rf]: Initialize RF MMIO registers and hardware state
// rf_hw_init_n008 [rf]: Initialize RF MMIO registers and hardware state
float rf_hw_init_n008()
{
  _DWORD *v0; // r4
  _DWORD *v1; // r2
  int v2; // r3
  int v3; // r0
  int v4; // r1
  unsigned int v5; // r4

  v0 = off_10E098;
  v1 = off_10E09C;
  v2 = dword_10E0A0;
  v3 = dword_10E0A4;
  v4 = dword_10E0A8;
  *(_DWORD *)off_10E098 = 0;
  v1[14] = 296;
  v0[2] = v0[2] & 0xF000FFFF | 0x2000000;
  v0[3] = v2 & v0[3] | 0xA06A000;
  v0[3] = v4 | v3 & v0[3];
  rf_subsystem_init();
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v5 = v0[4];
  rf_reg_write_cb(dword_10E0AC, 0, 15360);
  return (float)((float)((float)((float)v5 / flt_10E0B0) - 1.0) * flt_10E0B4)
       + (float)((float)((float)((float)v5 / flt_10E0B0) - 1.0) * flt_10E0B4);
}

