// v23 annotated: sub_12B3E8 @ 0x12b3e8
// Original: 12b3e8_sub_12B3E8.c
// Primary struct: vif_bssid_ref (cluster 2, 4 funcs)
// Fields: vif=0x0, bssid=0xe
//
// sub_12B3E8 @ 0x12b3e8, size 20 bytes
int __fastcall sub_12B3E8(int a1)
{
  if ( (*(_BYTE *)(a1 + 3) & 5) != 0 )
    return *(_DWORD *)(*(_DWORD *)off_12B3FC + 20);
  else
    return sub_12AFD4((unsigned __int16 *)a1);
}

