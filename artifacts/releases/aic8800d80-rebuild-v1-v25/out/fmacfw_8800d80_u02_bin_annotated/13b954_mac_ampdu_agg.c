// fwstruct annotate: 13b954_mac_ampdu_agg.c
// mac_ampdu_agg @ 0x13b954, size 24 bytes
// Doc: mac_ampdu_agg [mac]: MAC A-MPDU aggregation handler
// mac_ampdu_agg [mac]: MAC A-MPDU aggregation handler
int __fastcall mac_ampdu_agg(int a1, __int16 a2, char a3)
{
  int result; // r0

  result = (*(int (__fastcall **)(int, int))a1)(a1, (a2 - *(_WORD *)(a1 + 4)) & 0xFFF) + a1;
  *(_BYTE *)(result + 6) = a3;
  return result;
}

