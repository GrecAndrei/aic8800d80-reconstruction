// sub_128D64 @ 0x128d64, size 78 bytes
void sub_128D64()
{
  uint8_t *v0; // r5
  int v1; // r4
  int v2; // r6
  int v3; // r0

  v0 = off_128DB4;
  if ( *(uint8_t *)off_128DB4 )
  {
    if ( *((uint8_t *)off_128DB4 + 28) )
    {
      v1 = *((uint32_t *)off_128DBC + 2);
      *(uint32_t *)off_128DB8 |= 4u;
      v0[8] = 0;
      if ( v1 )
      {
        v2 = dword_128DC0;
        do
        {
          if ( !*(uint8_t *)(v1 + 106) )
          {
            if ( *(uint8_t *)(v1 + 108) )
            {
              v3 = *(unsigned __int8 *)(v1 + 116);
              if ( v3 != 255 && !sub_118DC4(v3, v2, v1) )
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

