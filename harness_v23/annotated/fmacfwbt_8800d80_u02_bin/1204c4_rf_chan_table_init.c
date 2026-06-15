// v23 annotated: rf_chan_table_init @ 0x1204c4
// Original: 1204c4_rf_chan_table_init.c
// Primary struct: <unclustered>
//
// rf_chan_table_init @ 0x1204c4, size 136 bytes
// Doc: rf_chan_table_init [rf]: Initializes RF channel table at offset 0x1e0 with size 0x78
// rf_chan_table_init [rf]: Initializes RF channel table at offset 0x1e0 with size 0x78
int __fastcall rf_chan_table_init(int result, int a2)
{
  int v2; // r4
  int v3; // r3
  int v4; // r1
  int v5; // r3
  int v6; // r3
  int v7; // r3

  v2 = *(_DWORD *)(result + 1200);
  v3 = result + 120 * a2;
  v4 = v3 + 480;
  *(_BYTE *)(v3 + 579) = 0;
  if ( v2 == v3 + 480 )
  {
    v5 = *(unsigned __int8 *)(result + 579);
    *(_DWORD *)(result + 1200) = 0;
    v4 = result + 480;
    if ( v5
      || (v4 = result + 600, *(_BYTE *)(result + 699))
      || (v4 = result + 720, *(_BYTE *)(result + 819))
      || (v4 = result + 840, *(_BYTE *)(result + 939)) )
    {
      *(_DWORD *)(result + 1200) = v4;
      return result;
    }
  }
  if ( *(_DWORD *)(result + 1204) == v4 )
  {
    v6 = *(unsigned __int8 *)(result + 1059);
    *(_DWORD *)(result + 1204) = 0;
    if ( v6 )
    {
      v7 = result + 960;
    }
    else
    {
      if ( !*(_BYTE *)(result + 1179) )
        return result;
      v7 = result + 1080;
    }
    *(_DWORD *)(result + 1204) = v7;
  }
  return result;
}

