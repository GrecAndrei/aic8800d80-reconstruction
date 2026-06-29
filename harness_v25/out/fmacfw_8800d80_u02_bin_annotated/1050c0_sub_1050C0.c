// fwstruct annotate: 1050c0_sub_1050C0.c
// sub_1050C0 @ 0x1050c0, size 172 bytes
int __fastcall sub_1050C0(__int16 a1, int a2, int a3, int a4)
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

  v4 = (unsigned int *)off_10516C;
  v5 = (int *)off_105180;
  v6 = dword_105170;
  v7 = off_105184;
  *(_DWORD *)off_10516C &= ~0x20000000u;
  *v5 = *v5 & v6 | 0x80;
  delay_us_0644(300);
  *v5 = v6 & *v5 | a1 & 0xFFF;
  *v7 = 0;
  delay_us_0644(2);
  *v7 = 8;
  delay_us_0644(300);
  v12 = off_105174;
  v13 = dword_105178;
  *v4 |= 0x40000000u;
  v14 = HIWORD(*v12) & 0x3FFF;
  v15 = *v4 & 0xBFFFFFFF;
  *(_WORD *)(a2 + 2 * (a3 + 16 * a4)) = v14;
  *v4 = v15;
  result = feature_guard_check(1, v13);
  if ( v14 > 0x3E80 )
    return msg_parse(dword_10517C, v17, v18);
  return result;
}

