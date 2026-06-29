// fwstruct annotate: 1219c4_sub_1219C4.c
// sub_1219C4 @ 0x1219c4, size 36 bytes
int __fastcall sub_1219C4(int a1, int a2, int a3)
{
  int v4; // r0
  int result; // r0

  __disable_irq();
  v4 = dword_1219EC;
  *(_DWORD *)off_1219E8 = 0;
  result = sub_11F504(v4, a1, a2, a3 & 0xFFFFF);
  while ( *(_DWORD *)off_1219F0 )
    ;
  return result;
}

