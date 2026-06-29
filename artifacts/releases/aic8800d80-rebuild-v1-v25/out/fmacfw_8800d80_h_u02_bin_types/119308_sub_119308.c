// sub_119308 @ 0x119308, size 80 bytes
__int16 * sub_119308(__int16 *result)
{
  int v1; // r2
  int v2; // r1
  uint32_t *v3; // r4
  int v4; // r3

  v1 = *((uint32_t *)result + 19);
  if ( *(uint32_t *)(v1 + 28) )
  {
    v2 = *((uint32_t *)off_119358 + 43);
    v3 = result;
    result = *(__int16 **)off_11935C;
    do
    {
      v4 = v3[9] & 0x380000;
      *(uint32_t *)(*(uint32_t *)(v1 + 32) - 3) = v2;
      if ( v4 == 3670016 )
        break;
      v3 = (uint32_t *)*v3;
      if ( *result < 0 && !v3 )
      {
        sub_12F32C(dword_119364, dword_119360, 909);
        __und(0xFFu);
      }
      v1 = v3[19];
    }
    while ( *(uint32_t *)(v1 + 28) );
  }
  return result;
}

