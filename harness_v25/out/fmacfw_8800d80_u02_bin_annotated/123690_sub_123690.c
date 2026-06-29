// fwstruct annotate: 123690_sub_123690.c
// sub_123690 @ 0x123690, size 54 bytes
int __fastcall sub_123690(int a1, _BYTE *a2, int a3, int a4)
{
  char v7; // r0
  char v9; // r6
  _BYTE *v10; // r0

  v7 = sub_127B5C(a2, a4);
  if ( a4 )
  {
    v9 = v7;
    v10 = (_BYTE *)sub_12C92C(71, a4, a3, 3);
    *v10 = *a2;
    v10[1] = v9;
    v10[2] = 4;
    sub_12C98C(v10);
  }
  return 0;
}

