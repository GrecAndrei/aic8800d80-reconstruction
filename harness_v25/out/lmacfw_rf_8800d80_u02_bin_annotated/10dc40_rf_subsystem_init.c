// fwstruct annotate: 10dc40_rf_subsystem_init.c
// rf_subsystem_init @ 0x10dc40, size 48 bytes
// Doc: rf_subsystem_init [rf]: Initialize lmac RF subsystem helper
// rf_subsystem_init [rf]: Initialize lmac RF subsystem helper
int rf_subsystem_init()
{
  int result; // r0
  _DWORD *v1; // r3

  result = rf_reg_write_cb(dword_10DC70, 2048, 15360);
  v1 = off_10DC74;
  *((_DWORD *)off_10DC74 + 2) |= 0xFu;
  v1[2] |= 0x10000000u;
  v1[3] &= 0xFFFFF7FE;
  return result;
}

