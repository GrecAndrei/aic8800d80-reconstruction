// v23 annotated: sub_119AF4 @ 0x119af4
// Original: 119af4_sub_119AF4.c
// Primary struct: <unclustered>
//
// sub_119AF4 @ 0x119af4, size 54 bytes
int __fastcall sub_119AF4(int a1, _BYTE *a2, int a3, int a4)
{
  char v7; // r0
  char v9; // r6
  _BYTE *v10; // r0

  v7 = sub_11BBA4(a2, a4);
  if ( a4 )
  {
    v9 = v7;
    v10 = (_BYTE *)sub_11DDF0(71, a4, a3, 3);
    *v10 = *a2;
    v10[1] = v9;
    v10[2] = 4;
    sub_11DE50(v10);
  }
  return 0;
}

