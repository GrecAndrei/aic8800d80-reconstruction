// sub_126E94 @ 0x126e94, size 124 bytes
void sub_126E94()
{
  int *v0; // r4
  int v1; // r5
  uint8_t *v2; // r7
  int v3; // r8
  uint32_t *v4; // r6

  v0 = *((int **)off_126F10 + 2);
  v1 = *((uint32_t *)off_126F14 + 10);
  mmio_set_bit7();
  *(uint32_t *)off_126F18 &= ~4u;
  if ( v0 )
  {
    v2 = off_126F1C;
    v3 = dword_126F24;
    v4 = off_126F20;
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
      sub_1194CC(*((unsigned __int8 *)v0 + 116), 0, 0);
      v0 = (int *)*v0;
    }
    while ( v0 );
  }
}

