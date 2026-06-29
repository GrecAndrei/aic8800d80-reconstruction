// sub_12AFD4 @ 0x12afd4, size 88 bytes
int  sub_12AFD4(unsigned __int16 *a1)
{
  int v1; // r3
  int result; // r0

  v1 = *a1;
  result = *(uint32_t *)(*(uint32_t *)off_12B02C + 16);
  if ( v1 == 2412
    || v1 == 2437
    || v1 == 2462
    || v1 == 2472
    || v1 == 5180
    || v1 == 5220
    || v1 == 5765
    || v1 == 5785
    || v1 == 5805 )
  {
    result += 20000;
  }
  return result;
}

