// fmac_obj_init_n_1eaa0 @ 0x11eaa0, size 78 bytes
// Doc: fmac_obj_init_n_1eaa0 [util]: Initialize FMAC object via sub-call and reg load
// fmac_obj_init_n_1eaa0 [util]: Initialize FMAC object via sub-call and reg load
int __fastcall fmac_obj_init_n_1eaa0(int a1)
{
  char *v2; // r0
  void *v3; // r0
  char v4; // r2

  sub_11DF7C(a1, *(_DWORD *)(a1 + 28));
  v2 = (char *)off_11EAF0;
  if ( *((_DWORD *)off_11EAF0 + 14) )
  {
    *(_BYTE *)(a1 + 16) |= 1u;
    *(_DWORD *)(a1 + 4) = 0;
    v3 = v2 + 56;
    return list_push_tail(v3);
  }
  v3 = off_11EAF4;
  if ( *(_DWORD *)off_11EAF4 )
  {
    v4 = *(_BYTE *)(a1 + 16);
    *(_DWORD *)(a1 + 4) = 0;
    *(_BYTE *)(a1 + 16) = v4 | 1;
    return list_push_tail(v3);
  }
  return sub_11E0B4(a1);
}

