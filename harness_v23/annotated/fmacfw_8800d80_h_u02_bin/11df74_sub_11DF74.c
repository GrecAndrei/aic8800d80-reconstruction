// v23 annotated: sub_11DF74 @ 0x11df74
// Original: 11df74_sub_11DF74.c
// Primary struct: <unclustered>
//
// sub_11DF74 @ 0x11df74, size 66 bytes
int __fastcall sub_11DF74(int result)
{
  unsigned int v1; // r3
  unsigned int v2; // r2
  unsigned int v3; // r2

  v1 = *(_DWORD *)(result + 152);
  if ( *(_BYTE *)(result + 156) )
  {
    v3 = *(_DWORD *)off_11DFBC & 0x80000000;
    if ( v1 < (*(_DWORD *)off_11DFBC & 0x7FFFFFFFu) )
      v3 += 0x80000000;
    *(_DWORD *)off_11DFBC = v1 | v3;
  }
  else
  {
    v2 = *(_DWORD *)off_11DFB8 & 0x80000000;
    if ( v1 < (*(_DWORD *)off_11DFB8 & 0x7FFFFFFFu) )
      v2 += 0x80000000;
    *(_DWORD *)off_11DFB8 = v1 | v2;
  }
  return result;
}

