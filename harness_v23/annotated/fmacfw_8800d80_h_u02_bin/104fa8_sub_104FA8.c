// v23 annotated: sub_104FA8 @ 0x104fa8
// Original: 104fa8_sub_104FA8.c
// Primary struct: <unclustered>
//
// sub_104FA8 @ 0x104fa8, size 172 bytes
int __fastcall sub_104FA8(__int16 a1, int a2, int a3, int a4)
{
  unsigned int *v4; // r4
  int *v5; // r9
  int v6; // r5
  _DWORD *v7; // r11
  _DWORD *v12; // r2
  int v13; // r1
  unsigned int v14; // r5
  unsigned int v15; // r0
  int result; // r0
  int v17; // r1
  int v18; // r2

  v4 = (unsigned int *)off_105054;
  v5 = (int *)off_105068;
  v6 = dword_105058;
  v7 = off_10506C;
  *(_DWORD *)off_105054 &= ~0x20000000u;
  *v5 = *v5 & v6 | 0x80;
  sub_100644(300);
  *v5 = v6 & *v5 | a1 & 0xFFF;
  *v7 = 0;
  sub_100644(2);
  *v7 = 8;
  sub_100644(300);
  v12 = off_10505C;
  v13 = dword_105060;
  *v4 |= 0x40000000u;
  v14 = HIWORD(*v12) & 0x3FFF;
  v15 = *v4 & 0xBFFFFFFF;
  *(_WORD *)(a2 + 2 * (a3 + 16 * a4)) = v14;
  *v4 = v15;
  result = sub_12EB90(1, v13);
  if ( v14 > 0x3E80 )
    return sub_12E948(dword_105064, v17, v18);
  return result;
}

