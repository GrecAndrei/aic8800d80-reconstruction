// fwstruct annotate: 1150a8_sub_1150A8.c
// sub_1150A8 @ 0x1150a8, size 330 bytes
void __fastcall sub_1150A8(int a1, int a2)
{
  int v2; // r3
  int v3; // r2
  int v4; // r1
  int v5; // r3
  int v6; // r0
  _DWORD *v7; // r3

  v2 = **(unsigned __int16 **)off_1151F4;
  if ( (v2 & 1) != 0 )
    sub_1216EC(a1, a2, v2 << 31);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1151F8 = 1;
  }
  v3 = dword_115200;
  v4 = dword_115204;
  v5 = *(_DWORD *)off_1151FC + 1;
  *(_DWORD *)off_1151FC = v5;
  sub_11F74C(1024, v4, v3, v5);
  v6 = sub_11E628(0x80000000);
  sub_11D348(v6);
  v7 = off_115208;
  *(_DWORD *)off_115208 &= 0xFFFFFFu;
  *v7 |= 0x10u;
  while ( 1 )
    ;
}

