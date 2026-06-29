// fwstruct annotate: 114a04_sub_114A04.c
// sub_114A04 @ 0x114a04, size 44 bytes
int __fastcall sub_114A04(_BYTE *a1)
{
  __int16 v2; // r0

  v2 = MEMORY[0x1FC](15);
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

