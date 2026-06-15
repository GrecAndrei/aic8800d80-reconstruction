// v23 annotated: sub_107824 @ 0x107824
// Original: 107824_sub_107824.c
// Primary struct: <unclustered>
//
// sub_107824 @ 0x107824, size 174 bytes
int __fastcall sub_107824(unsigned int *a1, int a2)
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
  sub_12EEF8(1, dword_1078D4);
  v6 = (int)(float)(COERCE_FLOAT(((int (__fastcall *)(_DWORD))sub_12D908)(vcvts_n_f32_u32(v3, 0xFu))) * 10.0);
  sub_12EEF8(1, dword_1078D8);
  if ( v6 >= -1 )
  {
    sub_12EEF8(1, dword_1078E0);
  }
  else if ( v6 < -30 )
  {
    sub_12EEF8(1, dword_1078DC);
  }
  *(_DWORD *)(a2 + 8) = (int)((float (__fastcall *)(_DWORD))sub_12D930)((float)(~v6 + v5));
  return sub_1075B8(a2);
}

