// sub_10D7B4 @ 0x10d7b4, size 34 bytes
uint8_t * sub_10D7B4(uint8_t *result)
{
  int v1; // r1
  uint32_t *v2; // r2
  uint32_t *v3; // r4
  int v4; // t1

  v1 = (unsigned __int8)*result;
  if ( *result )
  {
    v2 = off_10D7D8;
    v3 = off_10D7DC;
    do
    {
      while ( (*v2 & 0x80000) != 0 )
        ;
      *v3 = v1;
      v4 = (unsigned __int8)*++result;
      v1 = v4;
    }
    while ( v4 );
  }
  return result;
}

