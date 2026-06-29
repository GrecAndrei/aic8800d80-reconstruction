// fwstruct annotate: 1174ec_sub_1174EC.c
// sub_1174EC @ 0x1174ec, size 66 bytes
int __fastcall sub_1174EC(int result)
{
  unsigned int v1; // r3
  unsigned int v2; // r2
  unsigned int v3; // r2

  v1 = *(_DWORD *)(result + 148);
  if ( *(_BYTE *)(result + 152) )
  {
    v3 = *(_DWORD *)off_117534 & 0x80000000;
    if ( v1 < (*(_DWORD *)off_117534 & 0x7FFFFFFFu) )
      v3 += 0x80000000;
    *(_DWORD *)off_117534 = v1 | v3;
  }
  else
  {
    v2 = *(_DWORD *)off_117530 & 0x80000000;
    if ( v1 < (*(_DWORD *)off_117530 & 0x7FFFFFFFu) )
      v2 += 0x80000000;
    *(_DWORD *)off_117530 = v1 | v2;
  }
  return result;
}

