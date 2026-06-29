// sub_11A190 @ 0x11a190, size 22 bytes
int  sub_11A190(int result)
{
  char v1; // r3

  v1 = *(uint8_t *)(result + 14) - 1;
  *(uint8_t *)(result + 14) = v1;
  if ( !v1 )
    return sub_12D108(*(uint32_t *)(result + 340));
  return result;
}

