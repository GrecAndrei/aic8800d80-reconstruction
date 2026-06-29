// fwstruct annotate: 114754_sub_114754.c
// sub_114754 @ 0x114754, size 48 bytes
int __fastcall sub_114754(_BYTE *a1)
{
  unsigned int v2; // r0
  char v4; // r3

  v2 = MEMORY[0x1FC](6);
  if ( HIBYTE(v2) )
  {
    *a1 = HIBYTE(v2);
    return 0;
  }
  else
  {
    v4 = BYTE2(v2);
    if ( !HIWORD(v2) )
      v4 = 0;
    *a1 = v4;
    if ( HIWORD(v2) )
      return 1;
    else
      return 2;
  }
}

