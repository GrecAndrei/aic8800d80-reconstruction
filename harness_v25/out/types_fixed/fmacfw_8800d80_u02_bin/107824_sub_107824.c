// sub_107824 @ 0x107824, size 164 bytes
int __fastcall sub_107824(unsigned int a1, _DWORD *a2, int a3)
{
  int v3; // r8
  int v7; // s15

  v3 = *(_DWORD *)(a3 + 8);
  sub_12ECD0(1, dword_1078C8);
  sub_12ECD0(1, dword_1078CC);
  v7 = (int)(float)(COERCE_FLOAT(((int (__fastcall *)(_DWORD))sub_12D6E0)(vcvts_n_f32_u32(a1, 0xEu))) * 10.0);
  sub_12ECD0(1, dword_1078D0);
  if ( *(_DWORD *)(a2 + 0x20) < v7 )
  {
    sub_12ECD0(1, dword_1078D4);
    if ( *(_DWORD *)(a2 + 0x24) <= v7 )
      goto LABEL_3;
LABEL_5:
    sub_12ECD0(1, dword_1078D8);
    goto LABEL_3;
  }
  if ( *(_DWORD *)(a2 + 0x24) > v7 )
    goto LABEL_5;
LABEL_3:
  *(_DWORD *)(a3 + 8) = (int)((float (__fastcall *)(_DWORD))sub_12D708)((float)(unsigned int)(*(_DWORD *)(a2 + 0x1c) - v7 + v3));
  return sub_107760(a3);
}

