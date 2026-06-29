// fwstruct annotate: 114ea4_sub_114EA4.c
// sub_114EA4 @ 0x114ea4, size 44 bytes
// Doc: sub_1214EA4 [util]: Helper calling indirect function with arg 6 and inspecting high byte
// sub_1214EA4 [util]: Helper calling indirect function with arg 6 and inspecting high byte
int __fastcall sub_114EA4(_BYTE *a1)
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

