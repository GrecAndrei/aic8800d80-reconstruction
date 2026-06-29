// fwstruct annotate: 1306c4_sub_1306C4.c
// sub_1306C4 @ 0x1306c4, size 52 bytes
int __fastcall sub_1306C4(int a1, __int16 a2, __int16 a3, __int16 a4, char *a5)
{
  char *v5; // r2
  _BYTE *v6; // r3
  char v7; // t1

  *(_WORD *)a1 = a2;
  *(_WORD *)(a1 + 2) = a3;
  *(_WORD *)(a1 + 4) = a4;
  if ( !a5 )
    return 6;
  *(_BYTE *)(a1 + 6) = 16;
  *(_BYTE *)(a1 + 7) = 0x80;
  v5 = a5;
  do
  {
    v6 = v5 + 8;
    v7 = *v5++;
    *(_BYTE *)(v6 - a5 + a1) = v7;
  }
  while ( v5 != a5 + 128 );
  return 136;
}

