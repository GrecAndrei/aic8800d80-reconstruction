// sub_114C68 @ 0x114c68, size 464 bytes
int sub_114C68()
{
  _DWORD *v0; // r7
  int v1; // r6
  int *v2; // r5
  int i; // r4
  int v4; // r1
  int v5; // t1
  _DWORD *v6; // r5
  unsigned int v7; // r4
  int v8; // r3
  int v9; // r1
  int v10; // r1
  unsigned int CPSR; // r2
  unsigned int v12; // r3
  int result; // r0
  int v14; // r4
  int v15; // r4
  int v16; // r7
  int v17; // r6
  unsigned int v18; // r4
  unsigned int v19; // r5
  int v20; // t1
  int v21; // r8
  int v22; // r6
  unsigned int v23; // r4
  unsigned int v24; // r5
  int v25; // t1
  unsigned int v26; // [sp+0h] [bp-18h]

  v0 = off_114E38;
  v1 = dword_114E3C;
  v2 = (int *)off_114E38;
  for ( i = 0; i != 13; ++i )
  {
    v4 = i;
    v5 = *v2++;
    sub_10DA6C(v1, v4, v5);
  }
  v6 = off_114E40;
  sub_10DA6C(dword_114E44, v0[13], v0[14], v0[15], v0[16], v0[17], v0[18]);
  sub_10DA6C(dword_114E48, *v6, v6[1], v6[2], v6[3]);
  sub_10DA6C(dword_114E4C, v6[9], v6[10], v6[11], v6[12], v6[15]);
  v7 = v6[10];
  if ( (_BYTE)v7 )
  {
    sub_10DA6C(
      dword_114E78,
      (unsigned __int8)v6[10],
      v7 & 1,
      (v7 >> 1) & 1,
      (v7 >> 3) & 1,
      (v7 >> 4) & 1,
      (v7 >> 5) & 1,
      (v7 >> 7) & 1);
    if ( (v7 & 0x80) != 0 )
      sub_10DA6C(dword_114E7C, v6[13]);
  }
  if ( (v7 & 0xFF00) != 0 )
  {
    sub_10DA6C(
      dword_114E70,
      BYTE1(v7),
      (v7 >> 8) & 1,
      (v7 >> 9) & 1,
      (v7 >> 10) & 1,
      (v7 >> 11) & 1,
      (v7 >> 12) & 1,
      (v7 >> 13) & 1,
      (v7 >> 15) & 1);
    if ( (v7 & 0x8000) != 0 )
      sub_10DA6C(dword_114E74, *((_DWORD *)off_114E40 + 14));
  }
  if ( HIWORD(v7) )
    sub_10DA6C(
      dword_114E6C,
      HIWORD(v7),
      HIWORD(v7) & 1,
      (v7 >> 17) & 1,
      (v7 >> 18) & 1,
      (v7 >> 19) & 1,
      HIBYTE(v7) & 1,
      (v7 >> 25) & 1);
  if ( (v0[19] & 8) == 0 )
  {
    sub_10DA6C(dword_114E64);
    goto LABEL_9;
  }
  sub_10DA6C(dword_114E50);
  if ( (v0[20] & 1) == 0 )
  {
LABEL_9:
    sub_10DA6C(dword_114E54);
    goto LABEL_10;
  }
  sub_10DA6C(dword_114E68);
LABEL_10:
  v8 = v0[19];
  v9 = v8 << 29;
  if ( (v8 & 4) != 0 )
    sub_10DA6C(dword_114E58, v9);
  else
    sub_10DA6C(dword_114E5C, v9);
  v10 = v0[20];
  CPSR = __get_CPSR();
  v12 = __get_CPSR();
  v26 = __get_CPSR();
  result = sub_10DA6C(dword_114E60, v10, CPSR, v12, v26);
  v14 = v0[18];
  if ( v14 )
  {
    v21 = dword_114E84;
    v22 = dword_114E88;
    v23 = v14 & 0xFFFFFFF0;
    sub_10DA6C(dword_114E8C);
    v24 = v23 + 256;
    do
    {
      if ( !(v23 << 28) )
        sub_10DA6C(v21, v23);
      v25 = *(_DWORD *)v23;
      v23 += 4;
      result = sub_10DA6C(v22, v25);
    }
    while ( v24 != v23 );
  }
  v15 = v0[17];
  if ( v15 )
  {
    v16 = dword_114E84;
    v17 = dword_114E88;
    v18 = v15 & 0xFFFFFFF0;
    sub_10DA6C(dword_114E80);
    v19 = v18 + 256;
    do
    {
      if ( !(v18 << 28) )
        sub_10DA6C(v16, v18);
      v20 = *(_DWORD *)v18;
      v18 += 4;
      result = sub_10DA6C(v17, v20);
    }
    while ( v19 != v18 );
  }
  return result;
}

