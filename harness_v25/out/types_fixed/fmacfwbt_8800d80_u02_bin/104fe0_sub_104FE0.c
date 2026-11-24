// sub_104FE0 @ 0x104fe0, size 154 bytes
int __fastcall sub_104FE0(int a1, int a2, int a3)
{
  float v6; // s14
  __int64 v8; // r8
  __int64 v9; // r0
  int v10; // r0
  int v11; // r0
  float v12; // r0
  float v13; // s14
  __int64 v14; // r8
  __int64 v15; // r0
  int v16; // r0
  int v17; // r0

  if ( a1 > a2 )
  {
    v14 = sub_142A70(a1);
    v15 = sub_142A70(a2);
    v16 = sub_142D98(v14, HIDWORD(v14), v15, HIDWORD(v15));
    v17 = sub_143108(v16);
    v12 = COERCE_FLOAT(rf_state_check_n3ea_d908(v17));
    v13 = 20.0;
    goto LABEL_6;
  }
  if ( a1 < a2 )
  {
    v8 = sub_142A70(a2);
    v9 = sub_142A70(a1);
    v10 = sub_142D98(v8, HIDWORD(v8), v9, HIDWORD(v9));
    v11 = sub_143108(v10);
    v12 = COERCE_FLOAT(rf_state_check_n3ea_d908(v11));
    v13 = -20.0;
LABEL_6:
    v6 = v12 * v13;
    goto LABEL_4;
  }
  v6 = flt_10507C;
LABEL_4:
  *(float *)(a3 + 96) = v6;
  return feature_guard_sdio(1, dword_105080);
}

