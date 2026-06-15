// v23 annotated: rx_entry_lookup @ 0x13bac0
// Original: 13bac0_rx_entry_lookup.c
// Primary struct: <unclustered>
//
// rx_entry_lookup @ 0x13bac0, size 76 bytes
// Doc: rx_entry_lookup [rx]: Indexed lookup into 32-byte RX entry table returning descriptor fields
// rx_entry_lookup [rx]: Indexed lookup into 32-byte RX entry table returning descriptor fields
unsigned __int8 *__fastcall rx_entry_lookup(int a1)
{
  unsigned __int8 *result; // r0
  int v2; // r1
  int v3; // r3

  result = (unsigned __int8 *)(dword_13BB0C + 32 * a1);
  v2 = result[16];
  v3 = result[22];
  if ( result[17] )
  {
    if ( result[17] == 1 )
      *(_BYTE *)(696 * v2 + 12 * v3 + dword_13BB10 + 453) = 33;
  }
  else
  {
    *(_BYTE *)(696 * v2 + 12 * v3 + dword_13BB10 + 452) = 33;
  }
  return result;
}

