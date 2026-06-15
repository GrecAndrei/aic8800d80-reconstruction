// v23 annotated: sub_116E7C @ 0x116e7c
// Original: 116e7c_sub_116E7C.c
// Primary struct: <unclustered>
//
// sub_116E7C @ 0x116e7c, size 124 bytes
int sub_116E7C()
{
  int v0; // r0
  int v1; // r0
  char *v2; // r5
  char *v3; // r6
  char *v4; // r0
  _DWORD *v5; // r5
  int result; // r0

  sub_119D4C();
  sub_115F68();
  v0 = sub_1161D4();
  sub_117EDC(v0);
  v1 = sub_118AB0(0);
  sub_11BD88(v1);
  v2 = (char *)off_116EF8 + 12;
  sub_100200((int *)off_116EF8, 0, 0x204u);
  v3 = v2 + 420;
  do
  {
    sub_12D240(v2);
    *((_DWORD *)v2 - 3) = 0;
    v2[14] = 0;
    v2[68] = 0;
    *((_DWORD *)v2 + 6) = 0;
    *((_DWORD *)v2 + 7) = 0;
    v4 = v2 + 16;
    v2 += 84;
    sub_12D240(v4);
  }
  while ( v2 != v3 );
  v5 = off_116EF8;
  sub_12D240((char *)off_116EF8 + 432);
  v5[114] = 0;
  v5[115] = 0;
  v5[105] = 0;
  *((_BYTE *)v5 + 446) = 0;
  *((_BYTE *)v5 + 500) = 0;
  result = sub_12D240(v5 + 112);
  *((_WORD *)v5 + 254) = 0;
  return result;
}

