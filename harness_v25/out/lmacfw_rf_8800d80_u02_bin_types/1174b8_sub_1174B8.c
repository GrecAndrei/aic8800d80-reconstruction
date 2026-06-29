// sub_1174B8 @ 0x1174b8, size 44 bytes
// Doc: sub_12174B8 [mmio]: Modify MMIO register bits via masked read-modify-write
// sub_12174B8 [mmio]: Modify MMIO register bits via masked read-modify-write
unsigned int  sub_1174B8(int a1)
{
  unsigned int *v1; // r1
  unsigned int result; // r0

  v1 = (unsigned int *)off_1174E8;
  *(uint32_t *)off_1174E4 = (a1 << 10) & 0x400 | *(uint32_t *)off_1174E4 & 0xFFFFFBFF;
  result = (a1 << 19) & 0x80000 | *v1 & 0xFFF7FFFF;
  *v1 = result;
  return result;
}

