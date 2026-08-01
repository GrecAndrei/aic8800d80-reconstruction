// rf_set_frequency @ 0x122244, size 116 bytes
// Doc: rf_cmd_dispatch_284 [rf]: Dispatch RF command converting float result to u32 for parameter
// rf_cmd_dispatch_284 [rf]: Dispatch RF command converting float result to u32 for parameter
int rf_set_frequency()
{
  float inited; // r0
  float v1; // r0
  float v2; // r0
  float v3; // r0
  float v4; // r0

  inited = sdio_core_config_1();
  dispatch_event_handler(dword_1222B8, (unsigned int)inited);
  v1 = sdio_core_config_2();
  dispatch_event_handler(dword_1222BC, (unsigned int)v1);
  v2 = sdio_core_config_0();
  dispatch_event_handler(dword_1222C0, (unsigned int)v2);
  v3 = sdio_core_config_3();
  dispatch_event_handler(dword_1222C4, (unsigned int)v3);
  v4 = sdio_core_init();
  dispatch_event_handler(dword_1222C8, (unsigned int)v4);
  return 0;
}

