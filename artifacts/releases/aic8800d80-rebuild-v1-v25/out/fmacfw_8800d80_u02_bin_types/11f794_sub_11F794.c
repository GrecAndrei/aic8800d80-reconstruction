// sub_11F794 @ 0x11f794, size 38 bytes
// Doc: sub_121F794 [unknown]: Trampoline helper loading from constant pointer table
// sub_121F794 [unknown]: Trampoline helper loading from constant pointer table
int sub_11F794()
{
  uint32_t *i; // r5
  uint32_t *j; // r4
  int result; // r0

  for ( i = *((uint32_t **)off_11F7BC + 2); i; i = (uint32_t *)*i )
  {
    for ( j = (uint32_t *)i[60]; j; j = (uint32_t *)*j )
      result = sub_11F3CC((int)i, (int)j, 0);
  }
  return result;
}

