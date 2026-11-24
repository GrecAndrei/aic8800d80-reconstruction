// sub_11E0B4 @ 0x11e0b4, size 66 bytes
int __fastcall sub_11E0B4(int result)
{
  unsigned int v1; // r3
  unsigned int v2; // r2
  unsigned int v3; // r2

  v1 = *(_DWORD *)(result + 152);
  if ( *(_BYTE *)(result + 156) )
  {
    v3 = *(_DWORD *)off_11E0FC & 0x80000000;
    if ( v1 < (*(_DWORD *)off_11E0FC & 0x7FFFFFFFu) )
      v3 += 0x80000000;
    *(_DWORD *)off_11E0FC = v1 | v3;
  }
  else
  {
    v2 = *(_DWORD *)off_11E0F8 & 0x80000000;
    if ( v1 < (*(_DWORD *)off_11E0F8 & 0x7FFFFFFFu) )
      v2 += 0x80000000;
    *(_DWORD *)off_11E0F8 = v1 | v2;
  }
  return result;
}

