// rf_mem_read_n47e @ 0x10dd00, size 16 bytes
// Doc: rf_mem_read_n47e [rf]: Read RF register with bank/page decode from top nibble
// rf_mem_read_n47e [rf]: Read RF register with bank/page decode from top nibble
int  rf_mem_read_n47e(char a1)
{
  int result; // r0

  result = (1 << a1) | *(uint32_t *)off_10DD10;
  *(uint32_t *)off_10DD10 = result;
  return result;
}

