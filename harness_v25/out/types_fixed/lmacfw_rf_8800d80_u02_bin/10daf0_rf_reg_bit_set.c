// rf_reg_bit_set @ 0x10daf0, size 16 bytes
// Doc: rf_reg_bit_set [mmio]: Sets a bit in RF MMIO register at 0x4010b000
// rf_reg_bit_set [mmio]: Sets a bit in RF MMIO register at 0x4010b000
int __fastcall rf_reg_bit_set(char a1)
{
  int result; // r0

  result = (1 << a1) | *((_DWORD *)off_10DB00 + 2);
  *((_DWORD *)off_10DB00 + 2) = result;
  return result;
}

