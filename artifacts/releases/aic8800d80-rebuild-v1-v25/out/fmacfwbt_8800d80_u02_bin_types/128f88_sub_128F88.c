// sub_128F88 @ 0x128f88, size 78 bytes
void sub_128F88()
{
  uint8_t *v0; // r5
  int v1; // r4
  int v2; // r6
  int v3; // r0

  v0 = off_128FD8;
  if ( *(uint8_t *)off_128FD8 )
  {
    if ( *((uint8_t *)off_128FD8 + 28) )
    {
      v1 = *((uint32_t *)off_128FE0 + 2);
      *(uint32_t *)off_128FDC |= 4u;
      v0[8] = 0;
      if ( v1 )
      {
        v2 = dword_128FE4;
        do
        {
          if ( !*(uint8_t *)(v1 + 106) )
          {
            if ( *(uint8_t *)(v1 + 108) )
            {
              v3 = *(unsigned __int8 *)(v1 + 116);
              if ( v3 != 255 && !fmacfwbt_phy_chan_init(v3, v2, v1) )
                ++v0[8];
            }
          }
          v1 = *(uint32_t *)v1;
        }
        while ( v1 );
      }
    }
  }
}

