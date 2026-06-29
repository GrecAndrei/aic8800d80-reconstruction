// sub_12D594 @ 0x12d594, size 20 bytes
int  sub_12D594(uint32_t **a1)
{
  uint32_t *v1; // r3
  int result; // r0

  v1 = *a1;
  if ( !*a1 )
    return 0;
  result = 0;
  do
  {
    v1 = (uint32_t *)*v1;
    ++result;
  }
  while ( v1 );
  return result;
}

