// v23 annotated: sub_130C0C @ 0x130c0c
// Original: 130c0c_sub_130C0C.c
// Primary struct: <unclustered>
//
// sub_130C0C @ 0x130c0c, size 64 bytes
int __fastcall sub_130C0C(int a1, int a2, __int16 a3, char a4, __int16 a5)
{
  _BYTE *v5; // r4

  *(_BYTE *)(a1 + 2) = a4;
  *(_BYTE *)a1 = 3;
  v5 = off_130C4C;
  *(_WORD *)(a1 + 3) = a5;
  *(_BYTE *)(a1 + 1) = 1;
  if ( !v5[371] )
    a3 &= ~1u;
  *(_WORD *)(a1 + 5) = a3;
  if ( a5 )
  {
    *(_BYTE *)(a1 + 7) = 0;
    *(_BYTE *)(a1 + 8) = 0;
  }
  else
  {
    *(_WORD *)(a1 + 7) = *(_WORD *)(a2 + 14);
  }
  return 9;
}

