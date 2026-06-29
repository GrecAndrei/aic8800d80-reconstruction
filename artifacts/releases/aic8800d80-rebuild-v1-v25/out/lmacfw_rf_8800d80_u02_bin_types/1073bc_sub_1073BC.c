// sub_1073BC @ 0x1073bc, size 174 bytes
int  sub_1073BC(unsigned int *a1, int a2)
{
  unsigned int v2; // r3
  unsigned int v3; // r5
  int v5; // r7
  int v6; // s15
  int v7; // r3
  int v8; // r3

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
  v5 = *(uint32_t *)(a2 + 8);
  sub_11F74C(1, dword_10746C, v3, v2);
  v6 = (int)(float)(COERCE_FLOAT(((int ( *)(uint32_t))sub_11EAA0)(vcvts_n_f32_u32(v3, 0xFu))) * 10.0);
  sub_11F74C(1, dword_107470, v6, v7);
  v8 = v6 + 1;
  if ( v6 >= -1 )
  {
    sub_11F74C(1, dword_107478, -2, v8);
  }
  else if ( v6 < -30 )
  {
    sub_11F74C(1, dword_107474, -30, v8);
  }
  *(uint32_t *)(a2 + 8) = (int)((float ( *)(uint32_t))sub_11EAC8)((float)(~v6 + v5));
  return sub_107150(a2);
}

