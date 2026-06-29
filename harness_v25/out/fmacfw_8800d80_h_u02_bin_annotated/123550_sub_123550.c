// fwstruct annotate: 123550_sub_123550.c
// sub_123550 @ 0x123550, size 54 bytes
int __fastcall sub_123550(int a1, _BYTE *a2, int a3, int a4)
{
  char v7; // r0
  char v9; // r6
  _BYTE *v10; // r0

  v7 = sub_127A1C(a2, a4);
  if ( a4 )
  {
    v9 = v7;
    v10 = (_BYTE *)sub_12C7EC(71, a4, a3, 3);
    *v10 = *a2;
    v10[1] = v9;
    v10[2] = 4;
    sub_12C84C(v10);
  }
  return 0;
}

