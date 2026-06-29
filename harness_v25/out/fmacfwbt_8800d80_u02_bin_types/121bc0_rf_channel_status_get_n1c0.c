// rf_channel_status_get_n1c0 @ 0x121bc0, size 32 bytes
// Doc: rf_channel_status_get_n1c0 [rf]: Look up channel status byte in table and compare to 0x21
// rf_channel_status_get_n1c0 [rf]: Look up channel status byte in table and compare to 0x21
BOOL  rf_channel_status_get_n1c0(int a1, int a2)
{
  return *(unsigned __int8 *)(696 * a1 + 12 * a2 + dword_121BE0 + 452) != 33;
}

