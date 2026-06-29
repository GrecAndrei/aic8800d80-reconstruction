// sub_117290 @ 0x117290, size 30 bytes
int  sub_117290(int result)
{
  int v1; // r4

  if ( *(uint16_t *)(result + 4) )
  {
    v1 = result;
    result = *(uint32_t *)(result + 72);
    if ( result )
    {
      if ( (*(uint32_t *)(v1 + 36) & 0x200000) == 0 )
      {
        result = log_free_dispatch_2((uint32_t *)result);
        *(uint32_t *)(v1 + 72) = 0;
      }
    }
  }
  return result;
}

