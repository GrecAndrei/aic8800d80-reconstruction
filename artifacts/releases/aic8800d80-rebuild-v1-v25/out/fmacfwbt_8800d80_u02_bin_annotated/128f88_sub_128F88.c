// fwstruct annotate: 128f88_sub_128F88.c
// sub_128F88 @ 0x128f88, size 78 bytes
void sub_128F88()
{
  _BYTE *v0; // r5
  int v1; // r4
  int v2; // r6
  int v3; // r0

  v0 = off_128FD8;
  if ( *(_BYTE *)off_128FD8 )
  {
    if ( *((_BYTE *)off_128FD8 + 28) )
    {
      v1 = *((_DWORD *)off_128FE0 + 2);
      *(_DWORD *)off_128FDC |= 4u;
      v0[8] = 0;
      if ( v1 )
      {
        v2 = dword_128FE4;
        do
        {
          if ( !*(_BYTE *)(v1 + 106) )
          {
            if ( *(_BYTE *)(v1 + 108) )
            {
              v3 = *(unsigned __int8 *)(v1 + 116);
              if ( v3 != 255 && !fmacfwbt_phy_chan_init(v3, v2, v1) )
                ++v0[8];
            }
          }
          v1 = *(_DWORD *)v1;
        }
        while ( v1 );
      }
    }
  }
}

