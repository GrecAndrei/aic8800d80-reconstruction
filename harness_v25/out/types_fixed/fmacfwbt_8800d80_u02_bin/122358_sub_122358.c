// sub_122358 @ 0x122358, size 94 bytes
// Doc: sub_1222358 [unknown]: Update signed/unsigned fields in structure at offsets 0x8e-0x91
// sub_1222358 [unknown]: Update signed/unsigned fields in structure at offsets 0x8e-0x91
int __fastcall sub_122358(_BYTE *a1, int a2)
{
  int v2; // r3
  int result; // r0
  char v5; // r2
  int v6; // r6
  char v7; // r5
  _BYTE *v8; // r0

  v2 = (char)*(_DWORD *)(a1 + 0x23c);
  result = (char)*(_DWORD *)(a1 + 0x238);
  v5 = *(_DWORD *)(a1 + 0x240);
  v6 = (unsigned __int8)*(_DWORD *)(a1 + 0x244);
  *(_DWORD *)(a1 + 0x238) = a2;
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
    v8 = (_BYTE *)rf_bus_setup_n3a8(87, 13, 0, 3);
    *v8 = *(_DWORD *)(a1 + 0x1ac);
    *(_DWORD *)(v8 + 0x4) = v6;
    *(_DWORD *)(v8 + 0x8) = v7;
    result = sub_12CBB4(v8);
LABEL_7:
    *(_DWORD *)(a1 + 0x244) = v6;
  }
  return result;
}

