// fwstruct annotate: 12a564_sub_12A564.c
// sub_12A564 @ 0x12a564, size 102 bytes
char *__fastcall sub_12A564(int a1)
{
  int v1; // r7
  int v2; // r4
  unsigned __int8 *v3; // r6
  int v4; // r3
  int v5; // r4
  char v6; // r1

  v1 = dword_12A5CC;
  v2 = *(unsigned __int8 *)(a1 + 1225);
  v3 = (unsigned __int8 *)(dword_12A5CC + 140 * v2);
  v4 = v3[114];
  v3[115] = 0;
  if ( v4 )
  {
    sub_124E34(140 * v2 + 96 + v1);
    v3[114] = 0;
  }
  sub_129804(v3);
  v5 = v1 + 140 * v2;
  if ( *(_BYTE *)(v5 + 121) )
    v6 = 3;
  else
    v6 = 2;
  return sub_125CD8(*(unsigned __int8 *)(v5 + 113), v6);
}

