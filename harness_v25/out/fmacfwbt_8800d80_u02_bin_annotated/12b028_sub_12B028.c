// fwstruct annotate: 12b028_sub_12B028.c
// sub_12B028 @ 0x12b028, size 52 bytes
int *__fastcall sub_12B028(int a1)
{
  int v1; // r4
  int v2; // r6
  char v3; // r5
  int v4; // r7
  int *result; // r0
  int v6; // r3
  int v7; // r1

  v1 = dword_12B05C;
  v2 = dword_12B05C + 32 * a1;
  v3 = a1;
  v4 = 32 * a1;
  if ( *(_BYTE *)(v2 + 30) )
    sub_125058(dword_12B05C + 32 * a1);
  result = sub_100200((int *)v2, 0, 0x20u);
  v6 = v1 + v4;
  v7 = dword_12B060;
  *(_DWORD *)(v6 + 8) = v2;
  *(_BYTE *)(v6 + 28) = v3;
  *(_DWORD *)(v6 + 4) = v7;
  *(_DWORD *)(v6 + 24) = 3;
  return result;
}

