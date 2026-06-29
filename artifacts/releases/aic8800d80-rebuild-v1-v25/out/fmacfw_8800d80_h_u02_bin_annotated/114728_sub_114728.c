// fwstruct annotate: 114728_sub_114728.c
// sub_114728 @ 0x114728, size 44 bytes
int __fastcall sub_114728(_BYTE *a1)
{
  __int16 v2; // r0

  v2 = MEMORY[0x1FC](6);
  if ( (v2 & 0xFF00) != 0 )
  {
    *a1 = HIBYTE(v2);
    return 0;
  }
  else
  {
    *a1 = v2;
    if ( (_BYTE)v2 )
      return 1;
    else
      return 2;
  }
}

