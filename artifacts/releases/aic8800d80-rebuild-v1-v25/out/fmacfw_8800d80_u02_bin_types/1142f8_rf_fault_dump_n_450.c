// rf_fault_dump_n_450 @ 0x1142f8, size 24 bytes
// Doc: rf_fault_dump_n_450 [rf]: RF fault dump handler clearing fault structure fields
// rf_fault_dump_n_450 [rf]: RF fault dump handler clearing fault structure fields
int  rf_fault_dump_n_450(int a1)
{
  uint32_t *v1; // r2
  uint16_t *v2; // r1

  v1 = rf_fault_dump_n_438;
  v2 = rf_fault_dump_n_434;
  *((uint32_t *)rf_fault_dump_n_438 + 2) = a1;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = 0;
  *v1 = 0;
  v1[1] = 0;
  v2[6] = 0;
  return 1;
}

