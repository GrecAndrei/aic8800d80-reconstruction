// sub_1157D8 @ 0x1157d8, size 346 bytes
void __fastcall sub_1157D8(int a1, int a2)
{
  int v2; // r3
  int v3; // r1
  int v4; // r0
  _DWORD *v5; // r3

  v2 = **(unsigned __int16 **)off_115934;
  if ( (v2 & 1) != 0 )
    ((void (__fastcall *)(int, int, int))loc_12F194)(a1, a2, v2 << 31);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_115938 = 1;
  }
  v3 = dword_115944;
  ++*(_DWORD *)off_11593C;
  sub_12ECD0(1024, v3);
  v4 = sub_12D14C(0x80000000);
  sub_12BB4C(v4);
  v5 = off_115948;
  *(_DWORD *)off_115948 &= 0xFFFFFFu;
  *v5 |= 0x10u;
  while ( 1 )
    ;
}

