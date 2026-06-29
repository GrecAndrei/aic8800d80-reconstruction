// sub_10767C @ 0x10767c, size 164 bytes
int  sub_10767C(unsigned int a1, uint32_t *a2, int a3)
{
  int v3; // r8
  int v7; // s15

  v3 = *(uint32_t *)(a3 + 8);
  sub_12EEF8(1, dword_107720);
  sub_12EEF8(1, dword_107724);
  v7 = (int)(float)(COERCE_FLOAT(((int ( *)(uint32_t))sub_12D908)(vcvts_n_f32_u32(a1, 0xEu))) * 10.0);
  sub_12EEF8(1, dword_107728);
  if ( a2[8] < v7 )
  {
    sub_12EEF8(1, dword_10772C);
    if ( a2[9] <= v7 )
      goto LABEL_3;
LABEL_5:
    sub_12EEF8(1, dword_107730);
    goto LABEL_3;
  }
  if ( a2[9] > v7 )
    goto LABEL_5;
LABEL_3:
  *(uint32_t *)(a3 + 8) = (int)((float ( *)(uint32_t))sub_12D930)((float)(unsigned int)(a2[7] - v7 + v3));
  return sub_1075B8(a3);
}

