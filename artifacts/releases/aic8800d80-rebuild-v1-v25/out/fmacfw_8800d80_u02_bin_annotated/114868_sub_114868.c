// fwstruct annotate: 114868_sub_114868.c
// sub_114868 @ 0x114868, size 44 bytes
int __fastcall sub_114868(_BYTE *a1)
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

