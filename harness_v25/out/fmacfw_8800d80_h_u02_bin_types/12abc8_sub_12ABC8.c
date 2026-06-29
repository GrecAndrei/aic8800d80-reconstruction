// sub_12ABC8 @ 0x12abc8, size 22 bytes
int  sub_12ABC8(int result)
{
  if ( *(uint8_t *)(result + 1224) )
  {
    if ( *(uint8_t *)(result + 108) )
      *(uint32_t *)(result + 4) |= 0x40u;
  }
  return result;
}

