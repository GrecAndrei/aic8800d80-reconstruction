// fwstruct annotate: 105840_sub_105840.c
// sub_105840 @ 0x105840, size 190 bytes
int __fastcall sub_105840(unsigned int a1, _DWORD *a2)
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
  v4 = dword_105900;
  a2[16] = 8;
  result = sub_12EEF8(1, v4);
  if ( a1 )
  {
    v6 = dword_105904;
    v7 = dword_10590C;
    v8 = dword_105910;
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
      sub_12EEF8(1, v6);
      v10 = a2[a2[14] + 10];
      if ( v10 <= 7 )
      {
        result = sub_12EEF8(((1 << v9) & a1) >> v9, v7);
        if ( !a2[14] )
          a2[16] = a2[10];
        goto LABEL_3;
      }
      v11 = ((1 << v9) & a1) >> v9;
      if ( v10 > 15 )
      {
        result = sub_12EEF8(v11, v7);
        if ( !a2[14] )
          a2[15] = a2[10];
        goto LABEL_3;
      }
      result = sub_12EEF8(v11, v8);
      v12 = a2[14];
      ++v9;
      v13 = a2[v12 + 10];
      a2[14] = v12 + 1;
      a2[15] = v13;
      if ( v9 == 28 )
        return result;
    }
  }
  return sub_12EEF8(1, dword_105908);
}

