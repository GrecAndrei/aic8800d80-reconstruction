// rf_level_apply_n_1f8 @ 0x10767c, size 164 bytes
// Doc: rf_level_apply_n_1f8 [rf]: Applies RF level/tx-power settings
// rf_level_apply_n_1f8 [rf]: Applies RF level/tx-power settings
int __fastcall rf_level_apply_n_1f8(unsigned int a1, _DWORD *a2, int a3)
{
  int v3; // r8
  int v7; // s15

  v3 = *(_DWORD *)(a3 + 8);
  feature_guard_sdio(1, dword_107720);
  feature_guard_sdio(1, dword_107724);
  v7 = (int)(float)(COERCE_FLOAT(((int (__fastcall *)(_DWORD))rf_state_check_n3ea_d908)(vcvts_n_f32_u32(a1, 0xEu)))
                  * 10.0);
  feature_guard_sdio(1, dword_107728);
  if ( a2[8] < v7 )
  {
    feature_guard_sdio(1, dword_10772C);
    if ( a2[9] <= v7 )
      goto LABEL_3;
LABEL_5:
    feature_guard_sdio(1, dword_107730);
    goto LABEL_3;
  }
  if ( a2[9] > v7 )
    goto LABEL_5;
LABEL_3:
  *(_DWORD *)(a3 + 8) = (int)((float (__fastcall *)(_DWORD))sub_12D930)((float)(unsigned int)(a2[7] - v7 + v3));
  return crypto_state_dump(a3);
}

