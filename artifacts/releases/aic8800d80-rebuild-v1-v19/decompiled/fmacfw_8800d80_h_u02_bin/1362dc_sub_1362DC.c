// sub_1362DC @ 0x1362dc, size 84 bytes
int __fastcall sub_1362DC(int a1, unsigned __int8 *a2, __int16 a3, __int16 a4)
{
  int v7; // r4

  sub_12EB90(256, dword_136330);
  v7 = dword_136334 + 1320 * *a2;
  if ( *(_BYTE *)(v7 + 106) == 2 && *(_BYTE *)(v7 + 108) )
  {
    if ( sub_12CD48(7u) )
    {
      return 2;
    }
    else
    {
      sub_13688C(v7);
      return 0;
    }
  }
  else
  {
    sub_12C8D0(7171, a4, a3);
    return 0;
  }
}

