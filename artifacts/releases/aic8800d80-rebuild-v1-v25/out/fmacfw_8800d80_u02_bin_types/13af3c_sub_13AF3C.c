// sub_13AF3C @ 0x13af3c, size 64 bytes
int * sub_13AF3C(int *result)
{
  int v1; // r5

  v1 = **(uint32_t **)(dword_13AF7C + 696 * *((unsigned __int8 *)result + 29) + 188);
  if ( v1 )
  {
    if ( *(uint8_t *)(v1 + 96) == 1 )
      return sub_116174(
               (int)result,
               v1 + 80,
               result[18] - *((unsigned __int8 *)result + 52) + 172,
               *((unsigned __int8 *)result + 52) + *((unsigned __int16 *)result + 24));
  }
  return result;
}

