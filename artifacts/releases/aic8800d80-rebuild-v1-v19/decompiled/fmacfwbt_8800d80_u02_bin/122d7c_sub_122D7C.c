// sub_122D7C @ 0x122d7c, size 28 bytes
// Doc: sub_1222D7C [util]: Copy 8-byte record (ptr+4 bytes+halfword) to global table
// sub_1222D7C [util]: Copy 8-byte record (ptr+4 bytes+halfword) to global table
int __fastcall sub_122D7C(int a1, _DWORD *a2, int a3, int a4)
{
  int v4; // r0
  _DWORD *v5; // r5
  int v6; // r4
  int v7; // r1

  v4 = *a2;
  v5 = a2;
  v6 = dword_122D98;
  v7 = a2[1];
  LOWORD(v5) = *((_WORD *)v5 + 4);
  *(_DWORD *)dword_122D98 = v4;
  *(_DWORD *)(v6 + 4) = v7;
  *(_WORD *)(v6 + 8) = (_WORD)v5;
  message_dispatch_n84(138, a4, a3, a4);
  return 0;
}

