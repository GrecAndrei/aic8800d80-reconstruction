// sub_115698 @ 0x115698, size 346 bytes
void  sub_115698(int a1, int a2)
{
  int v2; // r3
  int v3; // r1
  int v4; // r0
  uint32_t *v5; // r3

  v2 = **(unsigned __int16 **)off_1157F4;
  if ( (v2 & 1) != 0 )
    ((void ( *)(int, int, int))loc_12F054)(a1, a2, v2 << 31);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1157F8 = 1;
  }
  v3 = dword_115804;
  ++*(uint32_t *)off_1157FC;
  sub_12EB90(1024, v3);
  v4 = sub_12D00C(0x80000000);
  sub_12BA0C(v4);
  v5 = off_115808;
  *(uint32_t *)off_115808 &= 0xFFFFFFu;
  *v5 |= 0x10u;
  while ( 1 )
    ;
}

