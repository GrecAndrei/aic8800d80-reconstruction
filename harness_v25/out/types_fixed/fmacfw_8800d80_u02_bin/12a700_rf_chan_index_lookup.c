// rf_chan_index_lookup @ 0x12a700, size 218 bytes
// Doc: rf_chan_index_lookup [rf]: Look up channel index in RF table by slot id at offset 0x4c9
// rf_chan_index_lookup [rf]: Look up channel index in RF table by slot id at offset 0x4c9
int __fastcall rf_chan_index_lookup(int a1, unsigned int a2, int a3)
{
  int v3; // r6
  int v4; // r5
  int result; // r0
  int v7; // r3
  unsigned int v8; // r8
  int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3

  v3 = *(unsigned __int8 *)(a1 + 1225);
  v4 = dword_12A7DC;
  result = *(unsigned __int8 *)(dword_12A7DC + 140 * v3 + 112);
  if ( result != 1 )
    return 1;
  if ( a2 <= 1 )
  {
    v7 = 140 * v3 + 48 * a2 + dword_12A7DC;
    if ( *(_BYTE *)(v7 + 16) )
    {
      if ( !a3 || *(_BYTE *)(v7 + 32) )
      {
        timestamp_remove(48 * a2 + 140 * v3 + dword_12A7DC);
        v8 = 140 * v3 + 48 * a2 + v4;
        *(_BYTE *)(v8 + 16) = 0;
        sub_129598(v4 + 140 * v3);
        sub_129804((unsigned __int8 *)(v4 + 140 * v3));
        v9 = v4 + 140 * v3;
        v10 = *(unsigned __int8 *)(v8 + 32);
        v11 = (unsigned __int8)(*(_BYTE *)(v9 + 121) - 1);
        *(_BYTE *)(v9 + 121) = v11;
        if ( v10 == 1 )
          --*(_BYTE *)(v9 + 122);
        v12 = v4 + 140 * v3;
        if ( *(_BYTE *)(v12 + 115) || v11 )
          sub_125CD8(*(unsigned __int8 *)(v4 + 140 * v3 + 113), 3);
        else
          sub_125CD8(*(unsigned __int8 *)(v12 + 113), 2);
        sub_129544(v4 + 140 * v3, a2);
        return 0;
      }
    }
  }
  return result;
}

