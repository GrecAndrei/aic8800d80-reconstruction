// sub_11A9BC @ 0x11a9bc, size 140 bytes
int __fastcall sub_11A9BC(unsigned __int8 *a1, void *a2)
{
  int v2; // r3

  v2 = *a1;
  if ( v2 << 28 )
  {
    a2 = (void *)(v2 & 1);
    *(_BYTE *)off_11AA48 = v2 & 1;
  }
  if ( (v2 & 0xF0) != 0 )
    *((_BYTE *)off_11AA4C + 408) = v2 & 0x10;
  if ( *(_DWORD *)(a1 + 0x4) )
  {
    a2 = off_11AA50;
    *(_DWORD *)off_11AA50 = *(_DWORD *)(a1 + 0x4) | *(_DWORD *)off_11AA50 & 0xFFFFFF00;
  }
  if ( *(_DWORD *)(a1 + 0x8) )
  {
    a2 = off_11AA54;
    *(_DWORD *)off_11AA54 = *(_DWORD *)(a1 + 0x8) | *(_DWORD *)off_11AA54 & 0xFFFFFF00;
  }
  if ( *(_DWORD *)(a1 + 0xc) )
  {
    a2 = off_11AA50;
    *(_DWORD *)off_11AA50 = *(_DWORD *)off_11AA50 & 0xFFF00FFF | (*(_DWORD *)(a1 + 0xc) << 12);
  }
  if ( *(_DWORD *)(a1 + 0x10) )
  {
    a2 = off_11AA54;
    *(_DWORD *)off_11AA54 = *(_DWORD *)off_11AA54 & 0xFFF00FFF | (*(_DWORD *)(a1 + 0x10) << 12);
  }
  msg_parse(dword_11AA58, a2);
  return rf_mem_read_f594(a1, 5, 1, 0);
}

