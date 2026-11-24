// sub_124C14 @ 0x124c14, size 140 bytes
int __fastcall sub_124C14(unsigned __int8 *a1, void *a2)
{
  int v2; // r3
  unsigned int v3; // r2

  v2 = *a1;
  v3 = v2 << 28;
  if ( v2 << 28 )
  {
    v3 = (unsigned int)off_124CA0;
    a2 = (void *)(v2 & 1);
    *(_BYTE *)off_124CA0 = v2 & 1;
  }
  if ( (v2 & 0xF0) != 0 )
  {
    v3 = (unsigned int)off_124CA4;
    *((_BYTE *)off_124CA4 + 408) = v2 & 0x10;
  }
  if ( *(_DWORD *)(a1 + 0x4) )
  {
    a2 = off_124CA8;
    v3 = *(_DWORD *)off_124CA8 & 0xFFFFFF00;
    *(_DWORD *)off_124CA8 = *(_DWORD *)(a1 + 0x4) | v3;
  }
  if ( *(_DWORD *)(a1 + 0x8) )
  {
    a2 = off_124CAC;
    v3 = *(_DWORD *)off_124CAC & 0xFFFFFF00;
    *(_DWORD *)off_124CAC = *(_DWORD *)(a1 + 0x8) | v3;
  }
  if ( *(_DWORD *)(a1 + 0xc) )
  {
    a2 = off_124CA8;
    v3 = *(_DWORD *)off_124CA8 & 0xFFF00FFF;
    *(_DWORD *)off_124CA8 = v3 | (*(_DWORD *)(a1 + 0xc) << 12);
  }
  if ( *(_DWORD *)(a1 + 0x10) )
  {
    a2 = off_124CAC;
    v3 = *(_DWORD *)off_124CAC & 0xFFF00FFF;
    *(_DWORD *)off_124CAC = v3 | (*(_DWORD *)(a1 + 0x10) << 12);
  }
  msg_parse(dword_124CB0, a2, v3);
  return rf_mem_read_eb18(a1, 5, 1, 0);
}

