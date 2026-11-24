// sub_109620 @ 0x109620, size 278 bytes
int __fastcall sub_109620(float *a1, float *a2)
{
  float v2; // s15
  float v3; // s14
  float v4; // s13

  v2 = *a1;
  v3 = *(_DWORD *)(a1 + 0x4);
  if ( *a1 < v3 && *a2 >= *(_DWORD *)(a2 + 0x4) )
    return 2;
  if ( v2 > v3 && *a2 <= *(_DWORD *)(a2 + 0x4) )
    return 2;
  v4 = *(_DWORD *)(a1 + 0x8);
  if ( v2 < v4 && *a2 >= *(_DWORD *)(a2 + 0x8) )
    return 2;
  if ( v2 > v4 && *a2 <= *(_DWORD *)(a2 + 0x8) || v3 < v4 && *(_DWORD *)(a2 + 0x4) >= *(_DWORD *)(a2 + 0x8) || v3 > v4 && *(_DWORD *)(a2 + 0x4) <= *(_DWORD *)(a2 + 0x8) )
    return 2;
  if ( *a2 > 0.0 && *(_DWORD *)(a2 + 0x4) > 0.0 && *(_DWORD *)(a2 + 0x8) > 0.0 )
    return 1;
  if ( *a2 >= 0.0 || *(_DWORD *)(a2 + 0x4) >= 0.0 )
    return 0;
  return *(_DWORD *)(a2 + 0x8) < 0.0;
}

