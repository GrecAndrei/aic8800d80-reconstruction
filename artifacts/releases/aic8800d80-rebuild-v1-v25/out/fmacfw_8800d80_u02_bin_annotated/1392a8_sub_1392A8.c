// fwstruct annotate: 1392a8_sub_1392A8.c
// sub_1392A8 @ 0x1392a8, size 76 bytes
// Doc: sub_12392A8 [util]: Generic firmware helper, context unclear
// sub_12392A8 [util]: Generic firmware helper, context unclear
int __fastcall sub_1392A8(int result, unsigned int a2)
{
  unsigned __int16 v2; // r2
  char v3; // r7
  char v4; // r4
  int v5; // r3
  int v6; // r3
  char v7; // r7
  __int16 v8; // r1

  if ( a2 )
  {
    v2 = 0;
    v3 = *(_BYTE *)(result + 10);
    do
    {
      v4 = *(_BYTE *)(result + 11);
      v5 = (v3 + (_BYTE)v2++) & 0x3F;
      v6 = result + 4 * v5;
      if ( !v4 )
        break;
      if ( *(_DWORD *)(v6 + 16) )
      {
        *(_DWORD *)(v6 + 16) = 0;
        *(_BYTE *)(result + 11) = v4 - 1;
      }
    }
    while ( v2 < a2 );
  }
  else
  {
    v3 = *(_BYTE *)(result + 10);
  }
  v7 = v3 + a2;
  v8 = (a2 + *(_WORD *)(result + 8)) & 0xFFF;
  *(_BYTE *)(result + 10) = v7 & 0x3F;
  *(_WORD *)(result + 8) = v8;
  return idx_table_lookup_n3958(result);
}

