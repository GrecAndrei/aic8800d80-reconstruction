// mmio_init_or_reset @ 0x10d1fc, size 26 bytes
// Doc: mmio_init_or_reset [mmio]: Initialize MMIO region and store caller pointer to shared config reg
// mmio_init_or_reset [mmio]: Initialize MMIO region and store caller pointer to shared config reg
int __fastcall mmio_init_or_reset(int a1, int a2, int a3)
{
  int result; // r0
  _DWORD *v5; // r3

  result = msg_parse(dword_10D218, a1, a3);
  v5 = off_10D220;
  *(_DWORD *)off_10D21C = a1;
  *v5 = 0x1000000;
  return result;
}

