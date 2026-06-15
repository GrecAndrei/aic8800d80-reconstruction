// v23 annotated: sub_12F694 @ 0x12f694
// Original: 12f694_sub_12F694.c
// Primary struct: <unclustered>
//
// sub_12F694 @ 0x12f694, size 36 bytes
int __fastcall sub_12F694(int a1, int a2, int a3)
{
  int v4; // r0
  int result; // r0

  __disable_irq();
  v4 = dword_12F6BC;
  *(_DWORD *)off_12F6B8 = 0;
  result = sub_12ECB0(v4, a1, a2, a3 & 0xFFFFF);
  while ( *(_DWORD *)off_12F6C0 )
    ;
  return result;
}

