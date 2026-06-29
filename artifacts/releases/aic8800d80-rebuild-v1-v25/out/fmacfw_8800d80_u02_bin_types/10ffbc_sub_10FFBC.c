// sub_10FFBC @ 0x10ffbc, size 62 bytes
uint32_t * sub_10FFBC(char a1)
{
  uint32_t *v2; // r4

  if ( **(uint8_t **)off_10FFFC == 1 )
    v2 = (uint32_t *)sub_110480();
  else
    v2 = sub_10FB28(dword_110000, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( sub_10FF34((unsigned int)v2) )
  {
    *((uint8_t *)v2 - 1) = a1;
    return v2;
  }
  sub_10DC24(dword_110004, v2);
  return v2;
}

