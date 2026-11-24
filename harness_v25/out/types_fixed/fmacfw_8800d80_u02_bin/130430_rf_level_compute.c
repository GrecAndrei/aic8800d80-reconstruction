// rf_level_compute @ 0x130430, size 110 bytes
// Doc: rf_level_compute [rf]: Compute RF signal level/threshold
// rf_level_compute [rf]: Compute RF signal level/threshold
int __fastcall rf_level_compute(int a1)
{
  signed int v1; // r0
  int v2; // r3
  int result; // r0

  if ( a1 > 29 )
    v1 = (unsigned int)(((unsigned int)dword_1304AC * (unsigned __int64)(unsigned int)(a1 - 30)) >> 32) >> 3;
  else
    v1 = ((int)((unsigned __int64)(dword_1304A0 * (__int64)(a1 - 40)) >> 32) >> 2) - ((a1 - 40) >> 31);
  if ( v1 >= 8 )
    v1 = 8;
  if ( v1 < -7 )
    v1 = -7;
  v2 = *((unsigned __int8 *)off_1304A4 + 4)
     + (char)(*(_BYTE *)(dword_1304A8 + v1 + 7) - *(_BYTE *)(dword_1304A8 + *((char *)off_1304A4 + 2) + 7));
  if ( v2 >= 31 )
    v2 = 31;
  if ( v2 < 1 )
    LOBYTE(v2) = 1;
  *((_BYTE *)off_1304A4 + 5) = v2;
  sub_1302F8(v1);
  result = rf_feature_check(9u, 4u);
  if ( result )
    return sub_1303A0();
  return result;
}

