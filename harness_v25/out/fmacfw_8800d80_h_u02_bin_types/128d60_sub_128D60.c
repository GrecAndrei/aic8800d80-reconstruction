// sub_128D60 @ 0x128d60, size 72 bytes
void sub_128D60()
{
  uint8_t *v0; // r5
  unsigned int *v1; // r1
  int v2; // r2
  int v3; // r4
  int v4; // r6
  int v5; // r0

  v0 = off_128DA8;
  if ( !*((uint8_t *)off_128DA8 + 28) )
  {
    v1 = (unsigned int *)off_128DAC;
    v2 = *(uint32_t *)off_128DAC;
    v3 = *((uint32_t *)off_128DB0 + 2);
    *((uint8_t *)off_128DA8 + 8) = 0;
    *v1 = v2 & 0xFFFFFFFB;
    if ( v3 )
    {
      v4 = dword_128DB4;
      do
      {
        if ( !*(uint8_t *)(v3 + 106) )
        {
          if ( *(uint8_t *)(v3 + 108) )
          {
            v5 = *(unsigned __int8 *)(v3 + 116);
            if ( v5 != 255 && !sub_118C84(v5, v4, v3) )
              ++v0[8];
          }
        }
        v3 = *(uint32_t *)v3;
      }
      while ( v3 );
    }
  }
}

