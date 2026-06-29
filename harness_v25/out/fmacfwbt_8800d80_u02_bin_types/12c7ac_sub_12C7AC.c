// sub_12C7AC @ 0x12c7ac, size 44 bytes
int  sub_12C7AC(int result)
{
  int *i; // r3
  int v2; // r2
  int v3; // r3

  v2 = *(char *)(result + 110);
  v3 = (char)(*(uint8_t *)(result + 420) - *(uint8_t *)(result + 464));
  if ( v2 == 127 )
  {
    *(uint8_t *)(result + 109) = 127;
    if ( v3 == 127 )
      return result;
  }
  else if ( v3 >= v2 )
  {
    LOBYTE(v3) = *(uint8_t *)(result + 110);
  }
  *(uint8_t *)(result + 109) = v3;
  for ( i = *(int **)(result + 240); i; i = (int *)*i )
    *((uint8_t *)i + 350) |= 0x10u;
  result = *(uint32_t *)(result + 72);
  if ( result )
    return sub_12876C(result);
  return result;
}

