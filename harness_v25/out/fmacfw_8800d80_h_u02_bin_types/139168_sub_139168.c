// sub_139168 @ 0x139168, size 76 bytes
int  sub_139168(int result, unsigned int a2)
{
  unsigned __int16 v2; // r2
  char v3; // r7
  char v4; // r4
  int v5; // r3
  int v6; // r3
  char v7; // r7
  __int16 v8; // r1

  if ( a2 )
  {
    v2 = 0;
    v3 = *(uint8_t *)(result + 10);
    do
    {
      v4 = *(uint8_t *)(result + 11);
      v5 = (v3 + (uint8_t)v2++) & 0x3F;
      v6 = result + 4 * v5;
      if ( !v4 )
        break;
      if ( *(uint32_t *)(v6 + 16) )
      {
        *(uint32_t *)(v6 + 16) = 0;
        *(uint8_t *)(result + 11) = v4 - 1;
      }
    }
    while ( v2 < a2 );
  }
  else
  {
    v3 = *(uint8_t *)(result + 10);
  }
  v7 = v3 + a2;
  v8 = (a2 + *(uint16_t *)(result + 8)) & 0xFFF;
  *(uint8_t *)(result + 10) = v7 & 0x3F;
  *(uint16_t *)(result + 8) = v8;
  return sub_138818(result);
}

