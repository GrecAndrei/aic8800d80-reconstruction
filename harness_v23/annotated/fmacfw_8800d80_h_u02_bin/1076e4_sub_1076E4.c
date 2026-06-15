// v23 annotated: sub_1076E4 @ 0x1076e4
// Original: 1076e4_sub_1076E4.c
// Primary struct: <unclustered>
//
// sub_1076E4 @ 0x1076e4, size 164 bytes
int __fastcall sub_1076E4(unsigned int a1, _DWORD *a2, int a3)
{
  int v3; // r8
  int v7; // s15

  v3 = *(_DWORD *)(a3 + 8);
  sub_12EB90(1, dword_107788);
  sub_12EB90(1, dword_10778C);
  v7 = (int)(float)(COERCE_FLOAT(((int (__fastcall *)(_DWORD))sub_12D5A0)(vcvts_n_f32_u32(a1, 0xEu))) * 10.0);
  sub_12EB90(1, dword_107790);
  if ( a2[8] < v7 )
  {
    sub_12EB90(1, dword_107794);
    if ( a2[9] <= v7 )
      goto LABEL_3;
LABEL_5:
    sub_12EB90(1, dword_107798);
    goto LABEL_3;
  }
  if ( a2[9] > v7 )
    goto LABEL_5;
LABEL_3:
  *(_DWORD *)(a3 + 8) = (int)((float (__fastcall *)(_DWORD))sub_12D5C8)((float)(unsigned int)(a2[7] - v7 + v3));
  return sub_107620(a3);
}

