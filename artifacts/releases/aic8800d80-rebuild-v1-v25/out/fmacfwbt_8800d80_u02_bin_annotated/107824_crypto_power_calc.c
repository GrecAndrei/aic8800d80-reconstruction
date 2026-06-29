// fwstruct annotate: 107824_crypto_power_calc.c
// crypto_power_calc @ 0x107824, size 174 bytes
// Doc: crypto_power_calc [ke]: Crypto/PKA power calculation helper clamping input parameters
// crypto_power_calc [ke]: Crypto/PKA power calculation helper clamping input parameters
int __fastcall crypto_power_calc(unsigned int *a1, int a2)
{
  unsigned int v2; // r3
  unsigned int v3; // r5
  int v5; // r7
  int v6; // s15

  v2 = *a1;
  if ( *a1 < a1[1] )
    v2 = a1[1];
  v3 = a1[3];
  if ( !v2 )
    v2 = 1;
  if ( v2 < a1[2] )
    v2 = a1[2];
  if ( v3 < v2 )
    v3 = v2;
  v5 = *(_DWORD *)(a2 + 8);
  feature_guard_sdio(1, dword_1078D4);
  v6 = (int)(float)(COERCE_FLOAT(((int (__fastcall *)(_DWORD))rf_state_check_n3ea_d908)(vcvts_n_f32_u32(v3, 0xFu)))
                  * 10.0);
  feature_guard_sdio(1, dword_1078D8);
  if ( v6 >= -1 )
  {
    feature_guard_sdio(1, dword_1078E0);
  }
  else if ( v6 < -30 )
  {
    feature_guard_sdio(1, dword_1078DC);
  }
  *(_DWORD *)(a2 + 8) = (int)((float (__fastcall *)(_DWORD))sub_12D930)((float)(~v6 + v5));
  return crypto_state_dump(a2);
}

