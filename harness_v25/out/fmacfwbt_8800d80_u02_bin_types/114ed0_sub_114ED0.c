// sub_114ED0 @ 0x114ed0, size 48 bytes
int  sub_114ED0(uint8_t *a1)
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

