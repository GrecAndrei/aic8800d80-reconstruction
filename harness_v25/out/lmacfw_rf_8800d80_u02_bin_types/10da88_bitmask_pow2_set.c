// bitmask_pow2_set @ 0x10da88, size 74 bytes
// Doc: bitmask_pow2_set [util]: Computes power-of-two bitmask for given bit index
// bitmask_pow2_set [util]: Computes power-of-two bitmask for given bit index
int  bitmask_pow2_set(int result)
{
  int v1; // r2

  v1 = 1 << result;
  if ( result <= 1 || (unsigned int)(result - 8) <= 1 )
  {
    result = 4 * result + 1079001088;
    *(uint32_t *)result = *(uint32_t *)result & 0xFFFFFFF0 | 1;
  }
  else if ( result <= 15 )
  {
    result = 4 * result + 1079001088;
    *(uint32_t *)result &= 0xFFFFFFF0;
  }
  *((uint32_t *)off_10DAD4 + 1) |= v1;
  return result;
}

