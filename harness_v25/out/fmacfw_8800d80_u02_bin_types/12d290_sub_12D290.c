// sub_12D290 @ 0x12d290, size 52 bytes
int  sub_12D290(int result, uint32_t *a2)
{
  uint32_t *v2; // r5

  v2 = (uint32_t *)result;
  if ( **(__int16 **)off_12D2C4 < 0 && !a2 )
    result = sub_12F46C(dword_12D2CC, dword_12D2C8, 95);
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

