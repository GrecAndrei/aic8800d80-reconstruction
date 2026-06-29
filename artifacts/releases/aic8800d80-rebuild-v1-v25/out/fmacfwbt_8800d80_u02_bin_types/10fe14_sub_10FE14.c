// sub_10FE14 @ 0x10fe14, size 62 bytes
uint32_t * sub_10FE14(char a1)
{
  uint32_t *v2; // r4

  if ( **(uint8_t **)off_10FE54 == 1 )
    v2 = (uint32_t *)sub_1102D8();
  else
    v2 = sub_10F980(dword_10FE58, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( sub_10FD8C((unsigned int)v2) )
  {
    *((uint8_t *)v2 - 1) = a1;
    return v2;
  }
  sub_10DA7C(dword_10FE5C, v2);
  return v2;
}

