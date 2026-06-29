// fwstruct annotate: 122244_rf_mem_write_n218.c
// rf_mem_write_n218 @ 0x122244, size 116 bytes
// Doc: rf_cmd_dispatch_284 [rf]: Dispatch RF command converting float result to u32 for parameter
// rf_cmd_dispatch_284 [rf]: Dispatch RF command converting float result to u32 for parameter
int rf_mem_write_n218()
{
  float inited; // r0
  float v1; // r0
  float v2; // r0
  float v3; // r0
  float v4; // r0

  inited = rf_hw_init_n008();
  msg_parse(dword_1222B8, (unsigned int)inited);
  v1 = mmio_init_n_0b8();
  msg_parse(dword_1222BC, (unsigned int)v1);
  v2 = rf_lmac_misc_n_df54();
  msg_parse(dword_1222C0, (unsigned int)v2);
  v3 = rf_subsystem_init_e170();
  msg_parse(dword_1222C4, (unsigned int)v3);
  v4 = sub_10E21C();
  msg_parse(dword_1222C8, (unsigned int)v4);
  return 0;
}

