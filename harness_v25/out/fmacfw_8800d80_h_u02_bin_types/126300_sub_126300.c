// sub_126300 @ 0x126300, size 44 bytes
int  sub_126300(uint32_t *a1)
{
  int v1; // r3
  int v2; // r2

  v1 = dword_12632C;
  while ( 1 )
  {
    if ( *(unsigned __int8 *)(v1 + 24) != 255 )
    {
      v2 = *(unsigned __int8 *)(v1 + 27);
      if ( v2 != 255 )
        break;
    }
    v1 += 28;
    if ( v1 == dword_12632C + 84 )
      return 0;
  }
  *a1 = dword_126330 + 1320 * v2;
  return 1;
}

