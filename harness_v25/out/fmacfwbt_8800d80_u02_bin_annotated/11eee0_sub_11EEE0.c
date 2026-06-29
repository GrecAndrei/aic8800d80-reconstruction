// fwstruct annotate: 11eee0_sub_11EEE0.c
// sub_11EEE0 @ 0x11eee0, size 78 bytes
int __fastcall sub_11EEE0(int a1)
{
  char *v2; // r0
  void *v3; // r0
  char v4; // r2

  sub_11E3BC(a1, *(_DWORD *)(a1 + 28));
  v2 = (char *)off_11EF30;
  if ( *((_DWORD *)off_11EF30 + 14) )
  {
    *(_BYTE *)(a1 + 16) |= 1u;
    *(_DWORD *)(a1 + 4) = 0;
    v3 = v2 + 56;
    return list_push_tail(v3);
  }
  v3 = off_11EF34;
  if ( *(_DWORD *)off_11EF34 )
  {
    v4 = *(_BYTE *)(a1 + 16);
    *(_DWORD *)(a1 + 4) = 0;
    *(_BYTE *)(a1 + 16) = v4 | 1;
    return list_push_tail(v3);
  }
  return rx_desc_status_get(a1);
}

