// rf_state_check_n3ea_d908 @ 0x12d908, size 26 bytes
// Doc: rf_state_check_n3ea_d908 [rf]: Check RF state via magic values
// rf_state_check_n3ea_d908 [rf]: Check RF state via magic values
float  rf_state_check_n3ea_d908(unsigned int a1)
{
  float v1; // r0
  uint64_t v2; // r0
  int v3; // r0

  v1 = sub_12D7CC(a1);
  v2 = sub_142A94(LODWORD(v1));
  v3 = sub_142B44(v2, HIDWORD(v2), dword_12D928, dword_12D92C);
  return sub_143108(v3);
}

