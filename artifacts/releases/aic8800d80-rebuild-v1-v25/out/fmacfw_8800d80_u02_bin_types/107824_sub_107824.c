// sub_107824 @ 0x107824, size 164 bytes
int  sub_107824(unsigned int a1, uint32_t *a2, int a3)
{
  int v3; // r8
  int v7; // s15

  v3 = *(uint32_t *)(a3 + 8);
  sub_12ECD0(1, dword_1078C8);
  sub_12ECD0(1, dword_1078CC);
  v7 = (int)(float)(COERCE_FLOAT(((int ( *)(uint32_t))sub_12D6E0)(vcvts_n_f32_u32(a1, 0xEu))) * 10.0);
  sub_12ECD0(1, dword_1078D0);
  if ( a2[8] < v7 )
  {
    sub_12ECD0(1, dword_1078D4);
    if ( a2[9] <= v7 )
      goto LABEL_3;
LABEL_5:
    sub_12ECD0(1, dword_1078D8);
    goto LABEL_3;
  }
  if ( a2[9] > v7 )
    goto LABEL_5;
LABEL_3:
  *(uint32_t *)(a3 + 8) = (int)((float ( *)(uint32_t))sub_12D708)((float)(unsigned int)(a2[7] - v7 + v3));
  return sub_107760(a3);
}

