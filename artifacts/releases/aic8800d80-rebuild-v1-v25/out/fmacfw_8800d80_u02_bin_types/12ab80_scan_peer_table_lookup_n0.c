// scan_peer_table_lookup_n0 @ 0x12ab80, size 44 bytes
// Doc: scan_peer_table_lookup_n0 [scan]: Lookup peer entry in indexed 0x8c-stride table
// scan_peer_table_lookup_n0 [scan]: Lookup peer entry in indexed 0x8c-stride table
int  scan_peer_table_lookup_n0(int a1)
{
  unsigned __int8 *v1; // r3
  int result; // r0

  v1 = (unsigned __int8 *)(dword_12ABAC + 140 * a1);
  if ( v1[113] == 255 )
    return 0;
  result = v1[132];
  if ( v1[132] )
    return (unsigned __int8)(13 * v1[136] + 11);
  return result;
}

