// sub_11FACC @ 0x11facc, size 38 bytes
int sub_11FACC()
{
  uint32_t *i; // r5
  uint32_t *j; // r4
  int result; // r0

  for ( i = *((uint32_t **)off_11FAF4 + 2); i; i = (uint32_t *)*i )
  {
    for ( j = (uint32_t *)i[60]; j; j = (uint32_t *)*j )
      result = sub_11F704((int)i, (int)j, 0);
  }
  return result;
}

