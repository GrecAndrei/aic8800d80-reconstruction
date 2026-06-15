// v23 annotated: sub_12B080 @ 0x12b080
// Original: 12b080_sub_12B080.c
// Primary struct: <unclustered>
//
// sub_12B080 @ 0x12b080, size 124 bytes
int __fastcall sub_12B080(int a1, int a2, int a3, int a4)
{
  __int16 v4; // r6
  _BYTE *v6; // r4
  _BYTE *v7; // r2

  v4 = a4;
  v6 = (_BYTE *)sub_12C92C(2049, a4, a3, 1);
  sub_12CE88(2);
  sub_12ECD0(4, dword_12B100);
  if ( sub_12CE88(2) )
  {
    *v6 = 8;
    sub_12C98C(v6);
    return 0;
  }
  else
  {
    if ( **(__int16 **)off_12B104 < 0 && !*(_BYTE *)(a2 + 367) )
      sub_12F46C(dword_12B110, dword_12B10C, 73);
    v7 = off_12B108;
    *v6 = 0;
    *(_DWORD *)v7 = a2;
    v7[10] = 0;
    *((_WORD *)v7 + 4) = v4;
    sub_12B278(a2);
    sub_12C98C(v6);
    return 1;
  }
}

