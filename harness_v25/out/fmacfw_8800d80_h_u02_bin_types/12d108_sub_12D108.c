// sub_12D108 @ 0x12d108, size 60 bytes
int  sub_12D108(int result, uint32_t *a2)
{
  int v2; // r5

  v2 = result;
  if ( **(__int16 **)off_12D144 < 0 && !a2 )
    result = sub_12F32C(dword_12D14C, dword_12D148, 72);
  if ( *(uint32_t *)v2 )
    **(uint32_t **)(v2 + 4) = a2;
  else
    *(uint32_t *)v2 = a2;
  *(uint32_t *)(v2 + 4) = a2;
  *a2 = 0;
  return result;
}

