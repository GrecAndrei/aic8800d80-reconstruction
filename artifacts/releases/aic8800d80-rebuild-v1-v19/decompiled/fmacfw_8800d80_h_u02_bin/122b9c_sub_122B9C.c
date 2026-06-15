// sub_122B9C @ 0x122b9c, size 64 bytes
int __fastcall sub_122B9C(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v7; // r1
  _BYTE *v8; // r2
  BOOL v9; // r0

  if ( a2[1] != 255 )
    sub_13BBA8();
  v7 = *a2;
  v8 = off_122BE0;
  if ( *a2 )
    v7 = 1;
  v9 = a2[2] != 0;
  *(_BYTE *)off_122BDC = v9;
  *v8 = v7;
  sub_12E948(dword_122BE4, v7, v9);
  sub_12C8D0(100, a4, a3);
  return 0;
}

