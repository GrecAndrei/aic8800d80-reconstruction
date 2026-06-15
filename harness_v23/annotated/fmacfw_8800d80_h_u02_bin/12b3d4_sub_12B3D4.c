// v23 annotated: sub_12B3D4 @ 0x12b3d4
// Original: 12b3d4_sub_12B3D4.c
// Primary struct: vif_bssid_ref (cluster 2, 4 funcs)
// Fields: vif=0x0, bssid=0xe
//
// sub_12B3D4 @ 0x12b3d4, size 16 bytes
int sub_12B3D4()
{
  return *(_DWORD *)off_12B3E4 + 6 * *((unsigned __int8 *)off_12B3E4 + 10);
}

