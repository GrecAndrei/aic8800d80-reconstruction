// fwstruct annotate: 12f7a4_sub_12F7A4.c
// sub_12F7A4 @ 0x12f7a4, size 82 bytes
void __fastcall sub_12F7A4(int a1)
{
  int v2; // r0
  int v3; // r5
  _DWORD *v4; // r4

  if ( **(_BYTE **)off_12F7F8 == 3 )
  {
    v2 = sub_10CAA8();
    v3 = v2;
    if ( v2 )
    {
      *(_DWORD *)(a1 + 24) = 49374;
      sub_14380C(v2, a1, 28);
      v4 = off_12F7FC;
      while ( !*(_DWORD *)off_12F7FC )
        ;
      sub_12D470(*(_DWORD *)off_12F800 + 540, (_DWORD *)(v3 - 4));
      *v4 = 1;
      sub_10CAFC();
    }
    else
    {
      sub_12ECB0(dword_12F804);
    }
  }
}

