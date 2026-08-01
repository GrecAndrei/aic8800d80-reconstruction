// pmu_sleep_200000 @ 0x11dc68, size 8 bytes
int pmu_sleep_200000()
{
  return set_system_flag_1(0x200000);
}

