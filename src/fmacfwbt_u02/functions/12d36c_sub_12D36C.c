// pmu_sleep_10000000 @ 0x12d36c, size 8 bytes
int pmu_sleep_10000000()
{
  return set_system_flag_1(0x10000000);
}

