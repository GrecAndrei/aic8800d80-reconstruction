// crypto_power_apply @ 0x107824, size 164 bytes
// Doc: crypto_power_apply [util]: Apply crypto engine power/clock configuration
// crypto_power_apply [util]: Apply crypto engine power/clock configuration
int __fastcall crypto_power_apply(unsigned int a1, _DWORD *a2, int a3)
{
  int v3; // r8
  int v7; // s15

  v3 = *(_DWORD *)(a3 + 8);
  feature_guard_check(1, dword_1078C8);
  feature_guard_check(1, dword_1078CC);
  v7 = (int)(float)(COERCE_FLOAT(((int (__fastcall *)(_DWORD))sub_12D6E0)(vcvts_n_f32_u32(a1, 0xEu))) * 10.0);
  feature_guard_check(1, dword_1078D0);
  if ( a2[8] < v7 )
  {
    feature_guard_check(1, dword_1078D4);
    if ( a2[9] <= v7 )
      goto LABEL_3;
LABEL_5:
    feature_guard_check(1, dword_1078D8);
    goto LABEL_3;
  }
  if ( a2[9] > v7 )
    goto LABEL_5;
LABEL_3:
  *(_DWORD *)(a3 + 8) = (int)((float (__fastcall *)(_DWORD))sub_12D708)((float)(unsigned int)(a2[7] - v7 + v3));
  return crypto_state_dump(a3);
}

