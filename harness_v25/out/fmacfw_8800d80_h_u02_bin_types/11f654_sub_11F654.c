// sub_11F654 @ 0x11f654, size 38 bytes
int sub_11F654()
{
  uint32_t *i; // r5
  uint32_t *j; // r4
  int result; // r0

  for ( i = *((uint32_t **)off_11F67C + 2); i; i = (uint32_t *)*i )
  {
    for ( j = (uint32_t *)i[60]; j; j = (uint32_t *)*j )
      result = sub_11F28C((int)i, (int)j, 0);
  }
  return result;
}

