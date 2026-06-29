// sub_12AF2C @ 0x12af2c, size 22 bytes
int  sub_12AF2C(int result)
{
  if ( *(uint8_t *)(result + 1224) )
  {
    if ( *(uint8_t *)(result + 108) )
      *(uint32_t *)(result + 4) |= 0x40u;
  }
  return result;
}

