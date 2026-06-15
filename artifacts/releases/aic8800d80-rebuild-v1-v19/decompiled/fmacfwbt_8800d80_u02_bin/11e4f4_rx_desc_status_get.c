// rx_desc_status_get @ 0x11e4f4, size 66 bytes
// Doc: rx_desc_status_get [rx]: Reads descriptor status/control fields at offset 0x98/0x9c
// rx_desc_status_get [rx]: Reads descriptor status/control fields at offset 0x98/0x9c
int __fastcall rx_desc_status_get(int result)
{
  unsigned int v1; // r3
  unsigned int v2; // r2
  unsigned int v3; // r2

  v1 = *(_DWORD *)(result + 152);
  if ( *(_BYTE *)(result + 156) )
  {
    v3 = *(_DWORD *)off_11E53C & 0x80000000;
    if ( v1 < (*(_DWORD *)off_11E53C & 0x7FFFFFFFu) )
      v3 += 0x80000000;
    *(_DWORD *)off_11E53C = v1 | v3;
  }
  else
  {
    v2 = *(_DWORD *)off_11E538 & 0x80000000;
    if ( v1 < (*(_DWORD *)off_11E538 & 0x7FFFFFFFu) )
      v2 += 0x80000000;
    *(_DWORD *)off_11E538 = v1 | v2;
  }
  return result;
}

