// sub_10D02C @ 0x10d02c, size 48 bytes
// Doc: sub_120D02C [mmio]: Reads MMIO register 0x40035104 and processes bit flags
// sub_120D02C [mmio]: Reads MMIO register 0x40035104 and processes bit flags
int sub_10D02C()
{
  uint32_t *v0; // r4
  int *v1; // r7
  uint32_t *v2; // r6
  int v3; // r0
  int result; // r0

  v0 = off_10D05C;
  if ( (*(uint32_t *)off_10D05C & 2) != 0 )
  {
    v1 = (int *)off_10D060;
    v2 = off_10D064;
    do
    {
      v3 = *v1;
      *v2 = 2;
      sub_10CF48((uint16_t *)(v3 + 4));
    }
    while ( (*v0 & 2) != 0 );
  }
  result = sub_11E628(0x8000000);
  *(uint32_t *)off_10D068 = 2;
  return result;
}

