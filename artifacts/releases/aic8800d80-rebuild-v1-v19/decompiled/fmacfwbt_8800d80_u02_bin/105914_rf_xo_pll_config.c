// rf_xo_pll_config @ 0x105914, size 206 bytes
// Doc: rf_xo_pll_config [rf]: Configure RF crystal/PLL parameters
// rf_xo_pll_config [rf]: Configure RF crystal/PLL parameters
int __fastcall rf_xo_pll_config(unsigned int a1, int a2, int a3)
{
  int v5; // r5
  int v6; // r8
  int v7; // r10
  int v8; // r7
  int v9; // r9
  int result; // r0
  int v11; // r1
  int v12; // r2
  unsigned int v13; // r0
  int v14; // r2
  int v15; // r2
  int v16; // r1

  v5 = 0;
  *(_QWORD *)(a2 + 628) = 0x40000000FLL;
  *(_DWORD *)(a2 + 624) = 0;
  v6 = dword_1059F0;
  v7 = dword_1059F4;
  if ( a3 )
    v8 = 7;
  else
    v8 = 4;
  if ( a3 )
    v9 = 15;
  else
    v9 = 13;
  result = feature_guard_sdio(1, dword_1059E4);
  do
  {
    if ( a1 )
    {
      if ( ((1 << v5) & a1) >> v5 == 1 )
      {
        *(_DWORD *)(a2 + 4 * (*(_DWORD *)(a2 + 624) + 148)) = v5;
        feature_guard_sdio(1, v6);
        v13 = ((1 << v5) & a1) >> v5;
        v14 = *(_DWORD *)(a2 + 4 * (*(_DWORD *)(a2 + 624) + 148));
        if ( v14 < v8 )
        {
          result = feature_guard_sdio(v13, v7);
          v12 = *(_DWORD *)(a2 + 624);
          if ( !v12 )
          {
            v12 = *(_DWORD *)(a2 + 592);
            *(_DWORD *)(a2 + 632) = v12;
          }
        }
        else if ( v14 > v9 )
        {
          result = feature_guard_sdio(v13, v7);
          v12 = *(_DWORD *)(a2 + 624);
          if ( !v12 )
          {
            v12 = *(_DWORD *)(a2 + 592);
            *(_DWORD *)(a2 + 628) = v12;
          }
        }
        else
        {
          result = feature_guard_sdio(v13, dword_1059EC);
          v15 = *(_DWORD *)(a2 + 624);
          v16 = v15 + 148;
          v12 = v15 + 1;
          v11 = *(_DWORD *)(a2 + 4 * v16);
          *(_DWORD *)(a2 + 624) = v12;
          *(_DWORD *)(a2 + 628) = v11;
        }
      }
    }
    else
    {
      result = sub_12ECB0(dword_1059E8, v11, v12);
    }
    ++v5;
  }
  while ( v5 != 16 );
  return result;
}

