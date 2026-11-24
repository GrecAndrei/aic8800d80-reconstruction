// extract_top_nibble_flag @ 0x124e48, size 140 bytes
// Doc: extract_top_nibble_flag [util]: Read byte and extract high nibble as flag/selector
// extract_top_nibble_flag [util]: Read byte and extract high nibble as flag/selector
int __fastcall extract_top_nibble_flag(unsigned __int8 *a1, void *a2)
{
  int v2; // r3
  unsigned int v3; // r2

  v2 = *a1;
  v3 = v2 << 28;
  if ( v2 << 28 )
  {
    v3 = (unsigned int)off_124ED4;
    a2 = (void *)(v2 & 1);
    *(_BYTE *)off_124ED4 = v2 & 1;
  }
  if ( (v2 & 0xF0) != 0 )
  {
    v3 = (unsigned int)off_124ED8;
    *((_BYTE *)off_124ED8 + 408) = v2 & 0x10;
  }
  if ( *(_DWORD *)(a1 + 0x4) )
  {
    a2 = off_124EDC;
    v3 = *(_DWORD *)off_124EDC & 0xFFFFFF00;
    *(_DWORD *)off_124EDC = *(_DWORD *)(a1 + 0x4) | v3;
  }
  if ( *(_DWORD *)(a1 + 0x8) )
  {
    a2 = off_124EE0;
    v3 = *(_DWORD *)off_124EE0 & 0xFFFFFF00;
    *(_DWORD *)off_124EE0 = *(_DWORD *)(a1 + 0x8) | v3;
  }
  if ( *(_DWORD *)(a1 + 0xc) )
  {
    a2 = off_124EDC;
    v3 = *(_DWORD *)off_124EDC & 0xFFF00FFF;
    *(_DWORD *)off_124EDC = v3 | (*(_DWORD *)(a1 + 0xc) << 12);
  }
  if ( *(_DWORD *)(a1 + 0x10) )
  {
    a2 = off_124EE0;
    v3 = *(_DWORD *)off_124EE0 & 0xFFF00FFF;
    *(_DWORD *)off_124EE0 = v3 | (*(_DWORD *)(a1 + 0x10) << 12);
  }
  sub_12ECB0(dword_124EE4, a2, v3);
  return rf_mem_read_ed40(a1, 5, 1, 0);
}

