// sub_12D248 @ 0x12d248, size 60 bytes
int  sub_12D248(int result, uint32_t *a2)
{
  int v2; // r5

  v2 = result;
  if ( **(__int16 **)off_12D284 < 0 && !a2 )
    result = sub_12F46C(dword_12D28C, dword_12D288, 72);
  if ( *(uint32_t *)v2 )
    **(uint32_t **)(v2 + 4) = a2;
  else
    *(uint32_t *)v2 = a2;
  *(uint32_t *)(v2 + 4) = a2;
  *a2 = 0;
  return result;
}

