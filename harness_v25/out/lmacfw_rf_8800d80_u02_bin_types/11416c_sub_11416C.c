// sub_11416C @ 0x11416c, size 40 bytes
int  sub_11416C(uint8_t *a1)
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
    if ( (uint8_t)v2 )
      return 1;
    else
      return 2;
  }
}

