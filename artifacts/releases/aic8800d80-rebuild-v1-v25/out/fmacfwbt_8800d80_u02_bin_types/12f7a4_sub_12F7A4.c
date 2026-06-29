// sub_12F7A4 @ 0x12f7a4, size 82 bytes
void  sub_12F7A4(int a1)
{
  int v2; // r0
  int v3; // r5
  uint32_t *v4; // r4

  if ( **(uint8_t **)off_12F7F8 == 3 )
  {
    v2 = sub_10CAA8();
    v3 = v2;
    if ( v2 )
    {
      *(uint32_t *)(a1 + 24) = 49374;
      sub_14380C(v2, a1, 28);
      v4 = off_12F7FC;
      while ( !*(uint32_t *)off_12F7FC )
        ;
      sub_12D470(*(uint32_t *)off_12F800 + 540, (uint32_t *)(v3 - 4));
      *v4 = 1;
      sub_10CAFC();
    }
    else
    {
      sub_12ECB0(dword_12F804);
    }
  }
}

