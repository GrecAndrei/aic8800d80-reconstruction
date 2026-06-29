// sub_12B064 @ 0x12b064, size 48 bytes
int *sub_12B064()
{
  int *result; // r0
  uint8_t *v1; // r3
  int v2; // r1

  sub_12B028(0);
  sub_12B028(1);
  sub_12B028(2);
  result = sub_12B028(3);
  v1 = (uint8_t *)dword_12B094;
  v2 = dword_12B094 + 96;
  do
  {
    v1[1] = 0;
    v1[2] = 0;
    *v1 = 0;
    v1 += 3;
  }
  while ( v1 != (uint8_t *)v2 );
  return result;
}

