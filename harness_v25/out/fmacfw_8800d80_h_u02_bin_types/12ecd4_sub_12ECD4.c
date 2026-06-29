// sub_12ECD4 @ 0x12ecd4, size 82 bytes
int  sub_12ECD4(int a1, uint32_t *a2, __int16 a3, __int16 a4)
{
  uint32_t *v5; // r5
  int v6; // r0
  bool v7; // zf
  int v8; // r2

  v5 = (uint32_t *)sub_12C7EC(1036, a4, a3, 4u);
  v6 = *a2;
  v7 = *a2 << 30 == 0;
  v8 = a2[1];
  *v5 = 0;
  if ( !v7 )
    *v5 = 255;
  if ( v8 << 30 )
    *v5 = 1;
  sub_143630(v6, a2 + 2, v8);
  sub_12E948(dword_12ED28, *a2, a2[1] + *a2, a2[2], *v5);
  sub_12C84C((int)v5);
  return 0;
}

