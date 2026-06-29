// sub_1200D4 @ 0x1200d4, size 28 bytes
int  sub_1200D4(int result)
{
  uint32_t *v1; // r4
  int v2; // r5

  v1 = *(uint32_t **)(result + 240);
  if ( v1 )
  {
    v2 = result;
    do
    {
      result = sub_11F28C(v2, (int)v1, 0);
      v1 = (uint32_t *)*v1;
    }
    while ( v1 );
  }
  return result;
}

