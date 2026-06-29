// fwstruct annotate: 10dd00_rf_mem_read_n47e.c
// rf_mem_read_n47e @ 0x10dd00, size 16 bytes
// Doc: rf_mem_read_n47e [rf]: Read RF register with bank/page decode from top nibble
// rf_mem_read_n47e [rf]: Read RF register with bank/page decode from top nibble
int __fastcall rf_mem_read_n47e(char a1)
{
  int result; // r0

  result = (1 << a1) | *(_DWORD *)off_10DD10;
  *(_DWORD *)off_10DD10 = result;
  return result;
}

