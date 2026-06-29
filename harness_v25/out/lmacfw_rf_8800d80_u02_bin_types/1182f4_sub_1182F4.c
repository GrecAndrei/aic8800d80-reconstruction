// sub_1182F4 @ 0x1182f4, size 22 bytes
int sub_1182F4()
{
  uint32_t *i; // r4
  int result; // r0

  for ( i = *((uint32_t **)off_11830C + 2); i; i = (uint32_t *)*i )
    result = sub_1182C8((int)i);
  return result;
}

