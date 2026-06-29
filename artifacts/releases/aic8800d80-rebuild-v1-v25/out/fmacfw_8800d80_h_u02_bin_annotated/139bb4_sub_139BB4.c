// fwstruct annotate: 139bb4_sub_139BB4.c
// sub_139BB4 @ 0x139bb4, size 118 bytes
int sub_139BB4()
{
  _DWORD *v0; // r6
  int v1; // r4
  int v2; // r5
  _DWORD *v3; // r1
  int v4; // r3
  int result; // r0
  int v6; // r1

  v0 = (_DWORD *)(dword_139C2C + 16);
  sub_12D100((_DWORD *)dword_139C2C);
  v1 = dword_139C30;
  sub_12D100(v0);
  v2 = v1 + 4672;
  do
  {
    v3 = (_DWORD *)v1;
    v1 += 292;
    sub_12D108((int)v0, v3);
  }
  while ( v1 != v2 );
  sub_12D100((_DWORD *)dword_139C34);
  sub_12D100((_DWORD *)dword_139C38);
  sub_12D108(dword_139C34, (_DWORD *)dword_139C3C);
  sub_12D108(dword_139C34, (_DWORD *)dword_139C40);
  sub_12D108(dword_139C34, (_DWORD *)dword_139C44);
  v4 = dword_139C4C;
  result = dword_139C50;
  *((_WORD *)off_139C48 + 51) = -1;
  v6 = v4 + 15360;
  do
  {
    *(_BYTE *)(v4 - 52) = 0;
    *(_WORD *)(v4 + 8) = 0;
    *(_DWORD *)(v4 - 64) = result;
    *(_DWORD *)(v4 - 60) = v4;
    *(_DWORD *)(v4 - 48) = v4;
    v4 += 80;
  }
  while ( v6 != v4 );
  return result;
}

