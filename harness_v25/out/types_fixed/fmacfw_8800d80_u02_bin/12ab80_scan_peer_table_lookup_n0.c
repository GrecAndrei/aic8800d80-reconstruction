// scan_peer_table_lookup_n0 @ 0x12ab80, size 44 bytes
// Doc: scan_peer_table_lookup_n0 [scan]: Lookup peer entry in indexed 0x8c-stride table
// scan_peer_table_lookup_n0 [scan]: Lookup peer entry in indexed 0x8c-stride table
int __fastcall scan_peer_table_lookup_n0(int a1)
{
  unsigned __int8 *v1; // r3
  int result; // r0

  v1 = (unsigned __int8 *)(dword_12ABAC + 140 * a1);
  if ( *(_DWORD *)(v1 + 0x1c4) == 255 )
    return 0;
  result = *(_DWORD *)(v1 + 0x210);
  if ( *(_DWORD *)(v1 + 0x210) )
    return (unsigned __int8)(13 * *(_DWORD *)(v1 + 0x220) + 11);
  return result;
}

