// sub_128F58 @ 0x128f58, size 34 bytes
int __fastcall sub_128F58(int a1, __int16 a2)
{
  _BYTE *v2; // r2
  _BYTE *v3; // r3
  bool v4; // zf
  int (*v5)(void); // r3

  v2 = off_128F80;
  v3 = *(_BYTE **)off_128F7C;
  *((_WORD *)off_128F80 + 1) = a2;
  v4 = *v3 == 2;
  v5 = (int (*)(void))off_128F84;
  if ( !v4 && a1 )
    v5 = (int (*)(void))off_128F88;
  v2[8] = 0;
  return v5();
}

