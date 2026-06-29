// fwstruct annotate: 128e18_sub_128E18.c
// sub_128E18 @ 0x128e18, size 34 bytes
int __fastcall sub_128E18(int a1, __int16 a2)
{
  _BYTE *v2; // r2
  _BYTE *v3; // r3
  bool v4; // zf
  int (*v5)(void); // r3

  v2 = off_128E40;
  v3 = *(_BYTE **)off_128E3C;
  *((_WORD *)off_128E40 + 1) = a2;
  v4 = *v3 == 2;
  v5 = (int (*)(void))off_128E44;
  if ( !v4 && a1 )
    v5 = (int (*)(void))off_128E48;
  v2[8] = 0;
  return v5();
}

