// sub_113AD0 @ 0x113ad0, size 88 bytes
int  sub_113AD0(unsigned int a1, int a2)
{
  uint32_t *v4; // r3

  sub_10F188(1);
  while ( !*(uint32_t *)off_113B28 )
    ;
  if ( a1 <= 0x1F )
  {
    v4 = off_113B2C;
    *((uint32_t *)off_113B2C + 16) = 1;
    v4[19] = 34816;
    v4[21] = 629;
    __dsb(0xFu);
    v4[a1 + 512] = a2;
    v4[16] = 0;
    v4[19] = 0;
    v4[21] &= ~4u;
  }
  *(uint32_t *)off_113B28 = 1;
  return sub_10F188(0);
}

