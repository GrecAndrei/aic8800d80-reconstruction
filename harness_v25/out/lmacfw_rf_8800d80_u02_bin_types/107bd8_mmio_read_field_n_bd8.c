// mmio_read_field_n_bd8 @ 0x107bd8, size 60 bytes
// Doc: mmio_read_field_n_bd8 [mmio]: Read shifted field from MMIO register block
// mmio_read_field_n_bd8 [mmio]: Read shifted field from MMIO register block
int mmio_read_field_n_bd8()
{
  unsigned int *v0; // r5
  unsigned int v1; // r4
  int v2; // r6
  int result; // r0
  uint32_t *v4; // r2

  v0 = (unsigned int *)off_107C18;
  v1 = *(uint32_t *)off_107C18;
  v2 = *(uint32_t *)off_107C14 >> 20;
  result = sub_11F74C(1, dword_107C1C, v2, off_107C14);
  v4 = off_107C24;
  *v0 = dword_107C20 & (((HIWORD(v1) & 0xFFF) + v2) << 16) | *v0 & 0xF000FFFF;
  *v4 |= 0x800000u;
  return result;
}

