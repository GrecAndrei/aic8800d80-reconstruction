// rf_fault_dump_n_464 @ 0x1142e4, size 16 bytes
// Doc: rf_fault_dump_n_464 [rf]: Triggers RF fault dump to shared buffer
// rf_fault_dump_n_464 [rf]: Triggers RF fault dump to shared buffer
int rf_fault_dump_n_464()
{
  feature_guard_check(256, dword_1142F4);
  return 1;
}

