// sub_10DE94 @ 0x10de94, size 94 bytes
int sub_10DE94()
{
  _DWORD *v0; // r1
  _DWORD *v1; // r3
  int result; // r0

  sub_10DCA4(1);
  sub_10DCEC(1);
  sub_10DCA4(2);
  sub_10DCEC(2);
  if ( *((_BYTE *)off_10DEF4 + 369) )
  {
    sub_10DD00(1);
    sub_10DD00(2);
  }
  else
  {
    sub_10DD14(1);
    sub_10DD14(2);
  }
  sub_10DCD4(3);
  sub_10DD44(3, 2, dword_10DEF8);
  v0 = off_10DEFC;
  v1 = off_10DF04;
  result = dword_10DF08;
  *((_DWORD *)off_10DEFC + 1) = off_10DF00;
  *(_DWORD *)(v1 + 0x4) = result;
  *(_DWORD *)(v1 + 0x8) = 0;
  *(_DWORD *)(v0 + 0x8) = 0;
  return result;
}

