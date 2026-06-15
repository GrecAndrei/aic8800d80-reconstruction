// sub_117A7C @ 0x117a7c, size 246 bytes
__int64 sub_117A7C()
{
  _BYTE *v0; // r8
  int v1; // r10
  char *v2; // r5
  _BYTE *v3; // r4
  char *v4; // r9
  _BYTE *v5; // r7
  int v6; // r6
  int v7; // r11
  int v8; // r9
  int v9; // r0
  int v10; // r0
  int v11; // r0
  __int16 v12; // r7
  char *v13; // r0
  int i; // r6
  int v15; // r2
  __int64 result; // r0
  _DWORD *v17; // r3
  _BYTE v18[44]; // [sp+0h] [bp-2Ch] BYREF

  v0 = off_117B7C;
  v1 = dword_117B80;
  sub_12D00C(126976);
  v2 = v0 + 12;
  v3 = v18;
  v0[510] = 1;
  v4 = v0 + 12;
  v5 = v18;
  v6 = 0;
  do
  {
    v7 = (unsigned __int8)v6;
    sub_12D100(v5);
    sub_118800((unsigned __int8)v6++, v1, v5);
    sub_118800(v7, v4, v5);
    v1 += 8;
    v5 += 8;
    v4 += 84;
  }
  while ( v6 != 5 );
  v8 = dword_117B74;
  v9 = sub_1188B8(5);
  v10 = sub_119D34(v9);
  v11 = sub_117D9C(v10);
  sub_11BDA0(v11);
  v12 = *((_WORD *)v0 + 254);
  sub_100200((int *)(v8 - 432), 0, 0x204u);
  *((_WORD *)v0 + 254) = v12;
  do
  {
    sub_12D100(v2);
    *((_DWORD *)v2 - 3) = 0;
    v2[14] = 0;
    v2[68] = 0;
    *((_DWORD *)v2 + 6) = 0;
    *((_DWORD *)v2 + 7) = 0;
    v13 = v2 + 16;
    v2 += 84;
    sub_12D100(v13);
  }
  while ( v2 != (char *)v8 );
  for ( i = 0; i != 5; ++i )
  {
    if ( sub_12D190(v3) )
    {
      do
        sub_13ADE4();
      while ( sub_12D190(v3) );
      sub_11A6A8((unsigned __int8)i);
    }
    v3 += 8;
  }
  v15 = dword_117B78;
  result = (unsigned int)(dword_117B78 + 1152);
  do
  {
    v17 = (_DWORD *)(v15 - 36);
    do
      *v17++ = 0;
    while ( (_DWORD *)v15 != v17 );
    v15 += 36;
  }
  while ( (_DWORD)result != v15 );
  return result;
}

