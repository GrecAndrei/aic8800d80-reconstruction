// fwstruct annotate: 12cb54_sub_12CB54.c
// sub_12CB54 @ 0x12cb54, size 82 bytes
int __fastcall sub_12CB54(__int16 a1, __int16 a2, __int16 a3, unsigned int a4)
{
  int v8; // r0
  int v9; // r4

  v8 = sub_12CD0C(a4 + 12);
  v9 = v8;
  if ( **(__int16 **)off_12CBA8 < 0 && !v8 )
    sub_12F694(dword_12CBB0, dword_12CBAC, 145);
  *(_WORD *)(v9 + 4) = a1;
  *(_WORD *)(v9 + 6) = a2;
  *(_WORD *)(v9 + 8) = a3;
  *(_WORD *)(v9 + 10) = a4;
  *(_DWORD *)v9 = 0;
  sub_100200((int *)(v9 + 12), 0, a4);
  return v9 + 12;
}

