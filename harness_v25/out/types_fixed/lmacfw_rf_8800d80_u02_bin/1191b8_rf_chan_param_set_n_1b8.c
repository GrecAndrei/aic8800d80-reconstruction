// rf_chan_param_set_n_1b8 @ 0x1191b8, size 94 bytes
// Doc: rf_chan_param_set_n_1b8 [rf]: Store channel/band parameters into RF context byte fields
// rf_chan_param_set_n_1b8 [rf]: Store channel/band parameters into RF context byte fields
int __fastcall rf_chan_param_set_n_1b8(_BYTE *a1, int a2)
{
  int v2; // r3
  int result; // r0
  char v5; // r2
  int v6; // r6
  char v7; // r5
  _BYTE *v8; // r0

  v2 = (char)*(_DWORD *)(a1 + 0x1d8);
  result = (char)*(_DWORD *)(a1 + 0x1d4);
  v5 = *(_DWORD *)(a1 + 0x1dc);
  v6 = (unsigned __int8)*(_DWORD *)(a1 + 0x1e0);
  *(_DWORD *)(a1 + 0x1d4) = a2;
  if ( v2 )
  {
    v7 = a2;
    if ( v6 )
    {
      if ( v6 != 1 || result >= a2 || a2 <= v2 + v5 )
        goto LABEL_7;
      LOBYTE(v6) = 0;
    }
    else
    {
      if ( result <= a2 || a2 >= v2 - v5 )
        goto LABEL_7;
      LOBYTE(v6) = 1;
    }
    v8 = (_BYTE *)rf_setup_dispatch(87, 4, 0, 3);
    *v8 = *(_DWORD *)(a1 + 0x17c);
    *(_DWORD *)(v8 + 0x4) = v6;
    *(_DWORD *)(v8 + 0x8) = v7;
    result = sub_11DE50(v8);
LABEL_7:
    *(_DWORD *)(a1 + 0x1e0) = v6;
  }
  return result;
}

