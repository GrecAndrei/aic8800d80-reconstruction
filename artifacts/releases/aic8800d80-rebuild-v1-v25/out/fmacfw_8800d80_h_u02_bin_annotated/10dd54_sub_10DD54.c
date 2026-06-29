// fwstruct annotate: 10dd54_sub_10DD54.c
// sub_10DD54 @ 0x10dd54, size 94 bytes
int sub_10DD54()
{
  _DWORD *v0; // r1
  _DWORD *v1; // r3
  int result; // r0

  sub_10DB64(1);
  sub_10DBAC(1);
  sub_10DB64(2);
  sub_10DBAC(2);
  if ( *((_BYTE *)off_10DDB4 + 369) )
  {
    sub_10DBC0(1);
    sub_10DBC0(2);
  }
  else
  {
    sub_10DBD4(1);
    sub_10DBD4(2);
  }
  sub_10DB94(3);
  sub_10DC04(3, 2, dword_10DDB8);
  v0 = off_10DDBC;
  v1 = off_10DDC4;
  result = dword_10DDC8;
  *((_DWORD *)off_10DDBC + 1) = off_10DDC0;
  v1[1] = result;
  v1[2] = 0;
  v0[2] = 0;
  return result;
}

