// sub_126C70 @ 0x126c70, size 124 bytes
void sub_126C70()
{
  int *v0; // r4
  int v1; // r5
  uint8_t *v2; // r7
  int v3; // r8
  uint32_t *v4; // r6

  v0 = *((int **)off_126CEC + 2);
  v1 = *((uint32_t *)off_126CF0 + 10);
  sub_11C350();
  *(uint32_t *)off_126CF4 &= ~4u;
  if ( v0 )
  {
    v2 = off_126CF8;
    v3 = dword_126D00;
    v4 = off_126CFC;
    do
    {
      while ( 1 )
      {
        if ( v0[18] == v1 && !*((uint8_t *)v0 + 106) && *((uint8_t *)v0 + 108) )
        {
          if ( v2[2] )
            *v4 &= ~0x80000000;
          if ( !*((uint8_t *)v0 + 1224) || *(uint8_t *)(v3 + 140 * *((unsigned __int8 *)v0 + 1225) + 133) )
            break;
        }
        v0 = (int *)*v0;
        if ( !v0 )
          return;
      }
      sub_11908C(*((unsigned __int8 *)v0 + 116), 0, 0);
      v0 = (int *)*v0;
    }
    while ( v0 );
  }
}

