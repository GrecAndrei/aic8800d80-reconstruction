// rx_entry_lookup @ 0x13bac0, size 76 bytes
// Doc: rx_entry_lookup [rx]: Indexed lookup into 32-byte RX entry table returning descriptor fields
// rx_entry_lookup [rx]: Indexed lookup into 32-byte RX entry table returning descriptor fields
unsigned __int8 *__fastcall rx_entry_lookup(int a1)
{
  unsigned __int8 *result; // r0
  int v2; // r1
  int v3; // r3

  result = (unsigned __int8 *)(dword_13BB0C + 32 * a1);
  v2 = *(_DWORD *)(result + 0x40);
  v3 = *(_DWORD *)(result + 0x58);
  if ( *(_DWORD *)(result + 0x44) )
  {
    if ( *(_DWORD *)(result + 0x44) == 1 )
      *(_BYTE *)(696 * v2 + 12 * v3 + dword_13BB10 + 453) = 33;
  }
  else
  {
    *(_BYTE *)(696 * v2 + 12 * v3 + dword_13BB10 + 452) = 33;
  }
  return result;
}

