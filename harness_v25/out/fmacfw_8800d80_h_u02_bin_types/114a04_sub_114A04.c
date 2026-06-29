// sub_114A04 @ 0x114a04, size 44 bytes
int  sub_114A04(uint8_t *a1)
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
    if ( (uint8_t)v2 )
      return 1;
    else
      return 2;
  }
}

