// fwstruct annotate: 116d3c_sub_116D3C.c
// sub_116D3C @ 0x116d3c, size 124 bytes
int sub_116D3C()
{
  int v0; // r0
  int v1; // r0
  char *v2; // r5
  char *v3; // r6
  char *v4; // r0
  _DWORD *v5; // r5
  int result; // r0

  sub_119C0C();
  sub_115E28();
  v0 = sub_116094();
  sub_117D9C(v0);
  v1 = sub_118970(0);
  sub_11BC48(v1);
  v2 = (char *)off_116DB8 + 12;
  sub_100200((int *)off_116DB8, 0, 0x204u);
  v3 = v2 + 420;
  do
  {
    sub_12D100(v2);
    *((_DWORD *)v2 - 3) = 0;
    v2[14] = 0;
    v2[68] = 0;
    *((_DWORD *)v2 + 6) = 0;
    *((_DWORD *)v2 + 7) = 0;
    v4 = v2 + 16;
    v2 += 84;
    sub_12D100(v4);
  }
  while ( v2 != v3 );
  v5 = off_116DB8;
  sub_12D100((char *)off_116DB8 + 432);
  v5[114] = 0;
  v5[115] = 0;
  v5[105] = 0;
  *((_BYTE *)v5 + 446) = 0;
  *((_BYTE *)v5 + 500) = 0;
  result = sub_12D100(v5 + 112);
  *((_WORD *)v5 + 254) = 0;
  return result;
}

