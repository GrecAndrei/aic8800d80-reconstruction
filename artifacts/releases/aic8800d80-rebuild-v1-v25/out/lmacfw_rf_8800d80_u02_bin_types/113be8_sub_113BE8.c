// sub_113BE8 @ 0x113be8, size 44 bytes
int  sub_113BE8(uint8_t *a1)
{
  unsigned int v2; // r0
  char v4; // r3

  v2 = sub_113A44(6u);
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

