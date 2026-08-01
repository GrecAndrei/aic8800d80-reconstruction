// init_memory_regions @ 0x1138fc, size 18 bytes
int init_memory_regions()
{
  int v0; // r1
  int v1; // r2

  sys_cmu_clock_get(dword_113910);
  ke_event_schedule(dword_113914, v0, v1);
  return 1;
}

