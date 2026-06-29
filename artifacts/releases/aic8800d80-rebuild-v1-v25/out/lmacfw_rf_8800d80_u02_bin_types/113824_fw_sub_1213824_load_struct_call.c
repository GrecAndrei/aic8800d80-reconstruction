// fw_sub_1213824_load_struct_call @ 0x113824, size 24 bytes
int  fw_sub_1213824_load_struct_call(int a1)
{
  uint32_t *v1; // r2
  uint16_t *v2; // r1

  v1 = off_11383C;
  v2 = off_113840;
  *((uint32_t *)off_11383C + 2) = a1;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = 0;
  *v1 = 0;
  v1[1] = 0;
  v2[6] = 0;
  return 1;
}

