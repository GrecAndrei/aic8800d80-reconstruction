// mmio_reg_read_pair @ 0x11f0d4, size 68 bytes
// Doc: mmio_reg_read_pair [mmio]: Read paired MMIO registers at 0x403410b0/0x403410b4
// mmio_reg_read_pair [mmio]: Read paired MMIO registers at 0x403410b0/0x403410b4
QWORD *mmio_reg_read_pair()
{
  QWORD *result; // r0
  uint64_t v1; // [sp+4h] [bp-20h] BYREF
  int v2; // [sp+Ch] [bp-18h]
  int v3; // [sp+10h] [bp-14h]
  int v4; // [sp+14h] [bp-10h]
  int v5; // [sp+18h] [bp-Ch]

  v2 = *(uint32_t *)off_11F118;
  v3 = *(uint32_t *)dword_11F11C;
  v4 = *(uint32_t *)(dword_11F11C + 8 + 0xFFFFFFFC);
  v5 = *(uint32_t *)(dword_11F11C + 8);
  result = sub_101818(&v1, 0);
  if ( (v2 & 0xF) == 2 )
    return (QWORD *)rf_bt_state_check_n0a4(&v1);
  return result;
}

