// btlp_enter_sleep @ 0x119120, size 22 bytes
// Doc: btlp_enter_sleep [util]: Small helper loading a pointer and returning constant
// btlp_enter_sleep [util]: Small helper loading a pointer and returning constant
int btlp_enter_sleep()
{
  check_abort_flag(dword_119138);
  return set_system_flag_1(0x20000);
}

