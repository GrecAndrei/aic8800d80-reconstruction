// rf_stream_start2_n218 @ 0x10c750, size 114 bytes
// Doc: rf_stream_start2_n218 [rf]: RF stream start path 2 initialization
// rf_stream_start2_n218 [rf]: RF stream start path 2 initialization
int *rf_stream_start2_n218()
{
  int v0; // r4
  bool v1; // zf
  unsigned __int8 v2; // r1
  int **v3; // r4

  v0 = *((_DWORD *)off_10C7C4 + 23);
  memset_thunk((int *)dword_10C7C8, 0, 0x28u);
  memset_thunk((int *)dword_10C7CC, 0, 0x1E6Cu);
  if ( (*(_DWORD *)off_10C7D0 & 8) != 0 )
  {
    while ( (*(_DWORD *)off_10C7D0 & 0x10) == 0 )
      ;
    v3 = (int **)off_10C7D4;
  }
  else
  {
    v2 = v0 & 3;
    v1 = (v0 & 3) == 0;
    v3 = (int **)off_10C7D4;
    *(_DWORD *)off_10C7D0 |= 8u;
    if ( v1 )
      memset_thunk(*v3, v2, 0x248u);
    *(_DWORD *)off_10C7D0 |= 0x10u;
  }
  (*v3)[145] = *(_DWORD *)off_10C7D8;
  return sdio_dma_config();
}

