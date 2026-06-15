// sub_12F448 @ 0x12f448, size 82 bytes
void __fastcall sub_12F448(int a1)
{
  int v2; // r0
  int v3; // r5
  _DWORD *v4; // r4

  if ( **(_BYTE **)off_12F49C == 3 )
  {
    v2 = sub_10CB10();
    v3 = v2;
    if ( v2 )
    {
      *(_DWORD *)(a1 + 24) = 49374;
      sub_143630(v2, a1, 28);
      v4 = off_12F4A0;
      while ( !*(_DWORD *)off_12F4A0 )
        ;
      sub_12D108(*(_DWORD *)off_12F4A4 + 604, (_DWORD *)(v3 - 4));
      *v4 = 1;
      sub_10CB64();
    }
    else
    {
      sub_12E948(dword_12F4A8);
    }
  }
}

