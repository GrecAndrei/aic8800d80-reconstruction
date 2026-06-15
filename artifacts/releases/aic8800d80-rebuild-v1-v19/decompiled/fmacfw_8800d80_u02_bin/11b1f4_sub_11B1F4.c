// sub_11B1F4 @ 0x11b1f4, size 68 bytes
// Doc: mmio_setup_n_202 [mmio]: Set up MMIO buffer with offset and store pointer table
// mmio_setup_n_202 [mmio]: Set up MMIO buffer with offset and store pointer table
BOOL __fastcall sub_11B1F4(BOOL result)
{
  int v1; // r3
  _DWORD *v2; // r2
  int v3; // r4

  v1 = *(unsigned __int8 *)(result + 37);
  if ( *(_BYTE *)(result + 37) )
  {
    v3 = result;
    timestamp_update(off_11B238, *((_DWORD *)off_11B23C + 4) + 5000);
    return sub_1190B4(*(unsigned __int8 *)(v3 + 35), 0, 2500, 37, 5u, 2u, 0, 0);
  }
  else
  {
    v2 = off_11B238;
    *((_DWORD *)off_11B238 + 1) = v1;
    v2[2] = v1;
  }
  return result;
}

