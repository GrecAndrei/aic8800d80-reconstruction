// sub_141484 @ 0x141484, size 88 bytes
uint32_t *sub_141484()
{
  int v0; // r3
  int v1; // r0
  int v2; // r4
  uint32_t *result; // r0

  v0 = dword_1414DC;
  v1 = *(uint32_t *)(dword_1414DC + 6480) + 1;
  *(uint32_t *)(dword_1414DC + 6480) = v1;
  v2 = v0;
  do
  {
    if ( *(unsigned __int16 *)(v2 + 4) > 1u )
      *(uint16_t *)(v2 + 4) = 1;
    v2 += 528;
  }
  while ( v2 != v0 + 6336 );
  if ( v1 >= *(uint32_t *)(v2 + 148) )
  {
    result = sub_12CD34(0xBu, 0);
    *(uint32_t *)(v2 + 144) = -1;
  }
  else
  {
    sub_12CD34(0xBu, 4);
    return (uint32_t *)sub_12CA10(11264, 11, 11);
  }
  return result;
}

