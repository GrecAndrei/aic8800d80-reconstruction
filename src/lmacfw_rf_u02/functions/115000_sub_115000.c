// sys_init @ 0x115000, size 22 bytes
int sys_init()
{
  int v0; // r0
  int v1; // r0
  int v2; // r0

  v0 = nullsub_5();
  v1 = start_firmware(v0);
  v2 = init_event_control(v1);
  return clear_global_187218(v2);
}

