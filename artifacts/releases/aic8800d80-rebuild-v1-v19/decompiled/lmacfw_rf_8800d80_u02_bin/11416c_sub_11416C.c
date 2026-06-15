// sub_11416C @ 0x11416c, size 40 bytes
int __fastcall sub_11416C(_BYTE *a1)
{
  __int16 v2; // r0

  v2 = sub_113A44(0xFu);
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

