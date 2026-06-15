// rf_agc_check_nbf4 @ 0x10dbf4, size 64 bytes
// Doc: rf_agc_check_nbf4 [rf]: Checks AGC byte masked with 0xc0 equals 0xc0 at 0x180560
// rf_agc_check_nbf4 [rf]: Checks AGC byte masked with 0xc0 equals 0xc0 at 0x180560
int __fastcall rf_agc_check_nbf4(int a1)
{
  int v1; // r3
  int v2; // r0
  int v3; // r1

  v1 = dword_10DC3C;
  if ( (*(_BYTE *)off_10DC34 & 0xC0) == 0xC0 )
    v1 = dword_10DC38;
  v2 = 4 * a1;
  v3 = v1 + 16;
  do
  {
    *(_DWORD *)(v3 - 12) = *(_DWORD *)(v3 - 12) & 0xFFFFFFF3 | v2;
    v3 += 12;
  }
  while ( v1 + 208 != v3 );
  return lmac_sub_init(1, 16, 0x10u, v1);
}

