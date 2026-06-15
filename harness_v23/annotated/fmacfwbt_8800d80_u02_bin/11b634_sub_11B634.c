// v23 annotated: sub_11B634 @ 0x11b634
// Original: 11b634_sub_11B634.c
// Primary struct: <unclustered>
//
// sub_11B634 @ 0x11b634, size 68 bytes
BOOL __fastcall sub_11B634(BOOL result)
{
  int v1; // r3
  _DWORD *v2; // r2
  int v3; // r4

  v1 = *(unsigned __int8 *)(result + 37);
  if ( *(_BYTE *)(result + 37) )
  {
    v3 = result;
    timestamp_update_4f60(off_11B678, *((_DWORD *)off_11B67C + 4) + 5000);
    return sta_lookup_by_index(*(unsigned __int8 *)(v3 + 35), 0, 2500, 37, 5u, 2u, 0, 0);
  }
  else
  {
    v2 = off_11B678;
    *((_DWORD *)off_11B678 + 1) = v1;
    v2[2] = v1;
  }
  return result;
}

