// sub_120214 @ 0x120214, size 28 bytes
// Doc: sub_1220214 [mac]: Handle operation on context field at offset 0xf0
// sub_1220214 [mac]: Handle operation on context field at offset 0xf0
int  sub_120214(int result)
{
  uint32_t *v1; // r4
  int v2; // r5

  v1 = *(uint32_t **)(result + 240);
  if ( v1 )
  {
    v2 = result;
    do
    {
      result = sub_11F3CC(v2, (int)v1, 0);
      v1 = (uint32_t *)*v1;
    }
    while ( v1 );
  }
  return result;
}

