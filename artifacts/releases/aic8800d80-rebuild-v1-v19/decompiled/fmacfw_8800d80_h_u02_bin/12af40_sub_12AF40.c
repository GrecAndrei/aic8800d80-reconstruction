// sub_12AF40 @ 0x12af40, size 124 bytes
int __fastcall sub_12AF40(int a1, int a2, int a3, int a4)
{
  __int16 v4; // r6
  _BYTE *v6; // r4
  _BYTE *v7; // r2

  v4 = a4;
  v6 = (_BYTE *)sub_12C7EC(2049, a4, a3, 1);
  sub_12CD48(2);
  sub_12EB90(4, dword_12AFC0);
  if ( sub_12CD48(2) )
  {
    *v6 = 8;
    sub_12C84C(v6);
    return 0;
  }
  else
  {
    if ( **(__int16 **)off_12AFC4 < 0 && !*(_BYTE *)(a2 + 367) )
      sub_12F32C(dword_12AFD0, dword_12AFCC, 73);
    v7 = off_12AFC8;
    *v6 = 0;
    *(_DWORD *)v7 = a2;
    v7[10] = 0;
    *((_WORD *)v7 + 4) = v4;
    sub_12B138(a2);
    sub_12C84C(v6);
    return 1;
  }
}

