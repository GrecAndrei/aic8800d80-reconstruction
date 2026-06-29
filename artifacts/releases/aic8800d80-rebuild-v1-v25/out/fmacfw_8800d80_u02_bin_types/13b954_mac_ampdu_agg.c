// mac_ampdu_agg @ 0x13b954, size 24 bytes
// Doc: mac_ampdu_agg [mac]: MAC A-MPDU aggregation handler
// mac_ampdu_agg [mac]: MAC A-MPDU aggregation handler
int  mac_ampdu_agg(int a1, __int16 a2, char a3)
{
  int result; // r0

  result = (*(int ( **)(int, int))a1)(a1, (a2 - *(uint16_t *)(a1 + 4)) & 0xFFF) + a1;
  *(uint8_t *)(result + 6) = a3;
  return result;
}

