// mac_txq_flag_get @ 0x12a350, size 14 bytes
// Doc: mac_txq_flag_get [mac]: Read flag byte from per-TID tx queue entry table
// mac_txq_flag_get [mac]: Read flag byte from per-TID tx queue entry table
int __fastcall mac_txq_flag_get(int a1)
{
  return *(unsigned __int8 *)(dword_12A360 + 140 * a1 + 133);
}

