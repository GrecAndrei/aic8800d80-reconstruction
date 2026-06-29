// sub_1140F4 @ 0x1140f4, size 72 bytes
int sub_1140F4()
{
  uint32_t *v0; // r5
  void *v1; // r7
  int result; // r0
  int v3; // r6
  int v4; // r4

  v0 = off_11413C;
  v1 = off_114140;
  sub_12D100(*(uint32_t *)off_11413C + 628);
  result = sub_12D100(*v0 + 636);
  if ( *(uint16_t *)(*(uint32_t *)v1 + 8) )
  {
    v3 = dword_114144;
    v4 = 0;
    do
    {
      sub_10F9E8(v3, 0x6B8u);
      result = sub_12D108(*v0 + 628);
      ++v4;
    }
    while ( *(unsigned __int16 *)(*(uint32_t *)v1 + 8) > (unsigned int)(unsigned __int16)v4 );
  }
  return result;
}

