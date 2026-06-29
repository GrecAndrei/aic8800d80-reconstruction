// sub_1290C4 @ 0x1290c4, size 72 bytes
void sub_1290C4()
{
  uint8_t *v0; // r5
  unsigned int *v1; // r1
  int v2; // r2
  int v3; // r4
  void *v4; // r6
  int v5; // r0

  v0 = off_12910C;
  if ( !*((uint8_t *)off_12910C + 28) )
  {
    v1 = (unsigned int *)off_129110;
    v2 = *(uint32_t *)off_129110;
    v3 = *((uint32_t *)off_129114 + 2);
    *((uint8_t *)off_12910C + 8) = 0;
    *v1 = v2 & 0xFFFFFFFB;
    if ( v3 )
    {
      v4 = off_129118;
      do
      {
        if ( !*(uint8_t *)(v3 + 106) )
        {
          if ( *(uint8_t *)(v3 + 108) )
          {
            v5 = *(unsigned __int8 *)(v3 + 116);
            if ( v5 != 255 && !sub_119204(v5, (int)v4, v3) )
              ++v0[8];
          }
        }
        v3 = *(uint32_t *)v3;
      }
      while ( v3 );
    }
  }
}

