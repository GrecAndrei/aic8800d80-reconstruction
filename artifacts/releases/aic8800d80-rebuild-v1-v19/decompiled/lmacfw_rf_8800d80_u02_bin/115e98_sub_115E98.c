// sub_115E98 @ 0x115e98, size 208 bytes
_DWORD *sub_115E98()
{
  _BYTE *v0; // r5
  int v1; // r8
  char *v2; // r7
  int *v3; // r4
  int v4; // r6
  int v5; // r9
  int *v6; // r6
  int v7; // r0
  __int16 v8; // r4
  int v9; // r2
  _DWORD *result; // r0
  _DWORD *v11; // r3
  int v12; // [sp+0h] [bp-24h] BYREF

  v0 = off_115F68;
  v1 = dword_115F74;
  sub_11E628(1966080);
  v0[142] = 1;
  v2 = v0 + 12;
  v3 = &v12;
  v4 = 0;
  do
  {
    v5 = (unsigned __int8)v4;
    sub_11E71C(v3);
    sub_1160FC((unsigned __int8)v4++, v1, v3);
    sub_1160FC(v5, v2, v3);
    v1 += 8;
    v3 += 2;
    v2 += 28;
  }
  while ( v4 != 4 );
  v6 = (int *)off_115F6C;
  v7 = sub_116328(5, off_115F6C, 0);
  sub_115FBC(v7);
  v8 = *((_WORD *)v0 + 70);
  sub_100200(v6 - 31, 0, 0x94u);
  *((_WORD *)v0 + 70) = v8;
  sub_11E71C(v6 - 28);
  *(int *)((char *)v6 + 0xFFFFFF84) = 0;
  v0[26] = 0;
  sub_11E71C(v6 - 21);
  *((_DWORD *)v0 + 7) = 0;
  v0[54] = 0;
  sub_11E71C(v6 - 14);
  *((_DWORD *)v0 + 14) = 0;
  v0[82] = 0;
  sub_11E71C(v6 - 7);
  v9 = dword_115F70;
  *((_DWORD *)v0 + 21) = 0;
  v0[110] = 0;
  result = (_DWORD *)(v9 + 144);
  do
  {
    v11 = (_DWORD *)(v9 - 36);
    do
      *v11++ = 0;
    while ( v11 != (_DWORD *)v9 );
    v9 = (int)(v11 + 9);
  }
  while ( v11 + 9 != result );
  return result;
}

