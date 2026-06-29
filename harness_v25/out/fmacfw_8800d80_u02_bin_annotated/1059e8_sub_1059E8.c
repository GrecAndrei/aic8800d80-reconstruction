// fwstruct annotate: 1059e8_sub_1059E8.c
// sub_1059E8 @ 0x1059e8, size 190 bytes
int __fastcall sub_1059E8(unsigned int a1, _DWORD *a2)
{
  int v4; // r1
  int result; // r0
  int v6; // r7
  int v7; // r9
  int v8; // r8
  int v9; // r5
  int v10; // r2
  unsigned int v11; // r0
  int v12; // r3
  int v13; // r2

  a2[14] = 0;
  a2[15] = 15;
  v4 = dword_105AA8;
  a2[16] = 8;
  result = feature_guard_check(1, v4);
  if ( a1 )
  {
    v6 = dword_105AAC;
    v7 = dword_105AB4;
    v8 = dword_105AB8;
    v9 = 20;
    while ( 1 )
    {
      while ( ((1 << v9) & a1) >> v9 != 1 )
      {
LABEL_3:
        if ( ++v9 == 28 )
          return result;
      }
      a2[a2[14] + 10] = v9 - 12;
      feature_guard_check(1, v6);
      v10 = a2[a2[14] + 10];
      if ( v10 <= 7 )
      {
        result = feature_guard_check(((1 << v9) & a1) >> v9, v7);
        if ( !a2[14] )
          a2[16] = a2[10];
        goto LABEL_3;
      }
      v11 = ((1 << v9) & a1) >> v9;
      if ( v10 > 15 )
      {
        result = feature_guard_check(v11, v7);
        if ( !a2[14] )
          a2[15] = a2[10];
        goto LABEL_3;
      }
      result = feature_guard_check(v11, v8);
      v12 = a2[14];
      ++v9;
      v13 = a2[v12 + 10];
      a2[14] = v12 + 1;
      a2[15] = v13;
      if ( v9 == 28 )
        return result;
    }
  }
  return feature_guard_check(1, dword_105AB0);
}

