// v23 annotated: sub_12B400 @ 0x12b400
// Original: 12b400_sub_12B400.c
// Primary struct: vif_bssid_ref (cluster 2, 4 funcs)
// Fields: vif=0x0, bssid=0xe
//
// sub_12B400 @ 0x12b400, size 72 bytes
int sub_12B400()
{
  _DWORD *v0; // r4
  unsigned int v1; // r2
  int result; // r0

  if ( **(__int16 **)off_12B448 < 0 && *(_DWORD *)off_12B454 << 28 )
    return sub_12F2C8(dword_12B45C, dword_12B458, 105, *(_DWORD *)off_12B454);
  if ( (*(_DWORD *)off_12B44C & 0x80) != 0 )
  {
    v0 = off_12B450;
    v1 = *((_DWORD *)off_12B450 + 1) & 0xFFFFFFFB;
    *(_DWORD *)off_12B44C &= ~0x80u;
    v0[1] = v1;
    return sub_12CFC4(0x2000000);
  }
  return result;
}

