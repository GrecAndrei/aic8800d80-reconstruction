// fwstruct annotate: 10788c_sub_10788C.c
// sub_10788C @ 0x10788c, size 174 bytes
int __fastcall sub_10788C(unsigned int *a1, int a2)
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
  sub_12EB90(1, dword_10793C);
  v6 = (int)(float)(COERCE_FLOAT(((int (__fastcall *)(_DWORD))sub_12D5A0)(vcvts_n_f32_u32(v3, 0xFu))) * 10.0);
  sub_12EB90(1, dword_107940);
  if ( v6 >= -1 )
  {
    sub_12EB90(1, dword_107948);
  }
  else if ( v6 < -30 )
  {
    sub_12EB90(1, dword_107944);
  }
  *(_DWORD *)(a2 + 8) = (int)((float (__fastcall *)(_DWORD))sub_12D5C8)((float)(~v6 + v5));
  return sub_107620(a2);
}

