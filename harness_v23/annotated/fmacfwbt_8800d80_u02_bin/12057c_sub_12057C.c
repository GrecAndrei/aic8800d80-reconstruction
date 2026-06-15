// v23 annotated: sub_12057C @ 0x12057c
// Original: 12057c_sub_12057C.c
// Primary struct: group_19 (cluster 19)
//
// sub_12057C @ 0x12057c, size 40 bytes
int __fastcall sub_12057C(int result)
{
  int v1; // r4

  if ( *(_BYTE *)off_1205A4 && (*((_DWORD *)off_1205A4 + 1) & 8) == 0 )
  {
    v1 = result;
    if ( !*(_DWORD *)(result + 4) )
    {
      timestamp_remove_058(result + 48);
      return sub_11F82C(v1);
    }
  }
  return result;
}

