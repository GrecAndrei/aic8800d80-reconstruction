// rf_chan_flag_lookup @ 0x12193c, size 24 bytes
// Doc: rf_chan_flag_lookup [rf]: Look up channel/band flag from table (index*0x2b8 stride) and check value vs 0x21
// rf_chan_flag_lookup [rf]: Look up channel/band flag from table (index*0x2b8 stride) and check value vs 0x21
int  rf_chan_flag_lookup(int a1, int a2)
{
  return sub_121954(*(unsigned __int8 *)(696 * a1 + 12 * a2 + dword_12195C + 453));
}

