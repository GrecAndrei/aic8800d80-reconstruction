// setup_patch_data @ 0x114914, size 36 bytes
// Doc: setup_patch_data [bt]: Initializes BT subsystem entry with defaults
// setup_patch_data [bt]: Initializes BT subsystem entry with defaults
int setup_patch_data()
{
  int v0; // r1
  int v1; // r2

  command_enqueue(0, 0, dword_114938, dword_11493C, 1);
  init_osal_objects();
  return ke_event_schedule(dword_114940, v0, v1);
}

