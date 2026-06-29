// crypto_gain_clamp @ 0x104c08, size 168 bytes
// Doc: crypto_gain_clamp [util]: Computes scaled gain by dividing floating-point value by 20
// crypto_gain_clamp [util]: Computes scaled gain by dividing floating-point value by 20
int  crypto_gain_clamp(float a1, int a2, int a3)
{
  float v6; // r0
  uint64_t v7; // r0
  uint64_t v8; // r0
  __int16 v9; // r0
  uint64_t v10; // kr00_8
  uint64_t v12; // kr08_8

  v6 = sub_11E8E0(a1 / 20.0);
  v7 = sub_127570((float)a2 * v6);
  v8 = math_round(v7, HIDWORD(v7));
  v9 = sub_127B54(v8, HIDWORD(v8));
  if ( v9 <= 232 )
  {
    if ( v9 > 31 )
    {
      *(uint8_t *)(a3 + 104) = v9;
    }
    else
    {
      v12 = *(QWORD *)(a3 + 112);
      *(uint8_t *)(a3 + 104) = 32;
      if ( SHIDWORD(v12) < (int)v12 )
        msg_parse(dword_104CB8, HIDWORD(v12));
    }
  }
  else
  {
    v10 = *(QWORD *)(a3 + 112);
    *(uint8_t *)(a3 + 104) = -24;
    if ( SHIDWORD(v10) < (int)v10 )
      msg_parse(dword_104CBC, HIDWORD(v10));
  }
  return sub_11F74C(1, dword_104CB4, (int)(float)(a1 * flt_104CB0), a2);
}

