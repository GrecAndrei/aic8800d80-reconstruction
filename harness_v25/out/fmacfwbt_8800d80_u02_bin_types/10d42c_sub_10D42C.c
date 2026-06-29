// sub_10D42C @ 0x10d42c, size 68 bytes
int sub_10D42C()
{
  unsigned int *v0; // r2
  unsigned int v1; // r3
  int result; // r0
  uint32_t *v3; // r3

  v0 = (unsigned int *)off_10D470;
  v1 = *(uint32_t *)off_10D470;
  if ( (*(uint32_t *)off_10D470 & 1) == 0 )
  {
    v1 = v1 & 0xFFFFFCFE | 0x101;
    result = 17;
    *((uint32_t *)off_10D470 + 4) = 0;
    v0[5] = 0;
    v0[1] = 17;
    *v0 = v1;
  }
  if ( (v1 & 0x4000) == 0 )
    *(uint32_t *)off_10D470 = v1 | 0x4040;
  v3 = off_10D478;
  *(uint32_t *)(*((uint32_t *)off_10D474 + 2) + 148) = dword_10D47C;
  *v3 = 0x200000;
  return result;
}

