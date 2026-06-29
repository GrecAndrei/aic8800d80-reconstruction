// sub_12F448 @ 0x12f448, size 82 bytes
void  sub_12F448(int a1)
{
  int v2; // r0
  int v3; // r5
  uint32_t *v4; // r4

  if ( **(uint8_t **)off_12F49C == 3 )
  {
    v2 = sub_10CB10();
    v3 = v2;
    if ( v2 )
    {
      *(uint32_t *)(a1 + 24) = 49374;
      sub_143630(v2, a1, 28);
      v4 = off_12F4A0;
      while ( !*(uint32_t *)off_12F4A0 )
        ;
      sub_12D108(*(uint32_t *)off_12F4A4 + 604, (uint32_t *)(v3 - 4));
      *v4 = 1;
      sub_10CB64();
    }
    else
    {
      sub_12E948(dword_12F4A8);
    }
  }
}

