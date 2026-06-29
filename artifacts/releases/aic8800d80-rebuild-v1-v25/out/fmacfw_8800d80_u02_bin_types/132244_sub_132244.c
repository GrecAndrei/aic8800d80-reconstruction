// sub_132244 @ 0x132244, size 112 bytes
char * sub_132244(char *result, int a2)
{
  int v2; // r1
  char *v3; // r3
  char *v4; // r4
  int v5; // r2

  if ( result )
  {
    if ( result != (char *)1 || (unsigned __int8)(a2 - 1) > 0xB0u )
      return nullptr;
    result = (char *)*((unsigned __int8 *)off_1322B4 + 371);
    v2 = 5 * a2 + 5000;
    v3 = (char *)off_1322B4 + 202;
  }
  else
  {
    if ( (unsigned int)(a2 - 1) > 0xD )
      return result;
    if ( a2 == 14 )
      v2 = 2484;
    else
      v2 = 5 * a2 + 2407;
    result = (char *)*((unsigned __int8 *)off_1322B4 + 370);
    v3 = (char *)off_1322B4 + 118;
  }
  if ( result )
  {
    v4 = &v3[6 * (uint32_t)result];
    while ( 1 )
    {
      v5 = *(unsigned __int16 *)v3;
      result = v3;
      v3 += 6;
      if ( v5 == v2 )
        break;
      if ( v3 == v4 )
        return nullptr;
    }
  }
  return result;
}

