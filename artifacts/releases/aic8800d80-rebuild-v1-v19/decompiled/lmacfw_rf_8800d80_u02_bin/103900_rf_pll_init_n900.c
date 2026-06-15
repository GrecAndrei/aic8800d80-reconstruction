// rf_pll_init_n900 @ 0x103900, size 86 bytes
// Doc: rf_pll_init_n900 [rf]: Initialize RF PLL/clock registers at 0x40342004/0x40342228
// rf_pll_init_n900 [rf]: Initialize RF PLL/clock registers at 0x40342004/0x40342228
int rf_pll_init_n900()
{
  int *v0; // r4
  int v1; // r0
  int v2; // r1
  int *v3; // r3
  int v4; // r1
  _DWORD *v5; // r2
  int v6; // r0

  v0 = (int *)off_10395C;
  *(_DWORD *)off_103958 = 777;
  while ( *v0 < 0 )
    delay_us(1);
  msg_parse(dword_103960, *(_DWORD *)off_10395C);
  v1 = dword_103964;
  *(_DWORD *)off_103958 = 0;
  msg_parse(v1, v2);
  v3 = (int *)off_10396C;
  v4 = dword_103970;
  v5 = off_103974;
  *(_DWORD *)off_103968 = 0;
  *v3 = v4;
  v6 = dword_103978;
  *v5 &= 0xFF00FFFF;
  return msg_parse(v6, 0x4000);
}

