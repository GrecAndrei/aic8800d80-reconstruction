// mmio_write_40320150 @ 0x1264dc, size 70 bytes
// Doc: mmio_write_40320150 [mmio]: Writes value to MMIO register 0x40320150
// mmio_write_40320150 [mmio]: Writes value to MMIO register 0x40320150
int __fastcall mmio_write_40320150(int a1)
{
  _DWORD *v1; // r3
  int *v2; // r4
  int v3; // r1
  int v4; // r2
  int result; // r0
  bool v6; // nf
  _DWORD *v7; // r2

  *(_DWORD *)off_126524 = a1;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_126528 = 1;
  }
  v1 = off_12652C;
  v2 = (int *)off_126530;
  v3 = *(_DWORD *)off_12652C;
  v4 = *(_DWORD *)off_126530;
  result = *(_DWORD *)off_12652C + 1;
  v6 = (*(_DWORD *)off_126530 & 0x400) != 0;
  *(_DWORD *)off_12652C = result;
  if ( !v6 )
  {
    *(_DWORD *)off_126534 = 1024;
    *v2 = v4 | 0x400;
  }
  if ( result )
  {
    v7 = off_126528;
    *v1 = v3;
    if ( !v3 )
    {
      if ( *v7 )
        __enable_irq();
    }
  }
  return result;
}

