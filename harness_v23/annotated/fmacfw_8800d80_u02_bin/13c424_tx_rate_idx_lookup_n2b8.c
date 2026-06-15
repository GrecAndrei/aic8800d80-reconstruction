// v23 annotated: tx_rate_idx_lookup_n2b8 @ 0x13c424
// Original: 13c424_tx_rate_idx_lookup_n2b8.c
// Primary struct: <unclustered>
//
// tx_rate_idx_lookup_n2b8 @ 0x13c424, size 70 bytes
// Doc: tx_rate_idx_lookup_n2b8 [tx]: Lookup TX rate by index in 0x2b8-sized table, scale by 3*index, fetch int16 entry
// tx_rate_idx_lookup_n2b8 [tx]: Lookup TX rate by index in 0x2b8-sized table, scale by 3*index, fetch int16 entry
int __fastcall tx_rate_idx_lookup_n2b8(int a1, int a2)
{
  int result; // r0
  unsigned int v3; // r4

  result = 696 * a1 + 12 * a2 + dword_13C470;
  v3 = *(unsigned __int8 *)(result + 452);
  if ( **(__int16 **)off_13C46C < 0 && v3 > 0x20 )
    result = sub_12F46C(dword_13C480, dword_13C47C, 1152);
  *(_DWORD *)(dword_13C474 + 32 * v3 + 8) = *((_DWORD *)off_13C478 + 4);
  return result;
}

