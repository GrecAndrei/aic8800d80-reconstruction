// sub_12D150 @ 0x12d150, size 52 bytes
int  sub_12D150(int result, uint32_t *a2)
{
  uint32_t *v2; // r5

  v2 = (uint32_t *)result;
  if ( **(__int16 **)off_12D184 < 0 && !a2 )
    result = sub_12F32C(dword_12D18C, dword_12D188, 95);
  if ( *v2 )
  {
    *a2 = *v2;
  }
  else
  {
    v2[1] = a2;
    *a2 = 0;
  }
  *v2 = a2;
  return result;
}

