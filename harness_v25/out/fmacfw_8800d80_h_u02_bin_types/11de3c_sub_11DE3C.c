// sub_11DE3C @ 0x11de3c, size 98 bytes
int  sub_11DE3C(int a1, int a2)
{
  int v2; // r3
  int result; // r0
  unsigned int v4; // r3
  uint32_t *v5; // r1
  int v6; // r2
  bool v7; // cf
  unsigned int v8; // r2

  if ( !a2 )
  {
    v4 = a1 + 160;
    goto LABEL_9;
  }
  if ( (*(uint16_t *)(a2 + 16) & 1) != 0 )
  {
LABEL_8:
    v4 = (*(uint32_t *)(a2 + 12) & 0xFFFFFFFC) + 4;
LABEL_9:
    v5 = off_11DEAC;
    v6 = *((uint32_t *)off_11DEAC + 2);
    if ( *((uint32_t *)off_11DEAC + 1) == v4 )
      v4 = *(uint32_t *)off_11DEAC;
    *(uint32_t *)(a1 + 152) = v4;
    result = v6 & 0x7FFFFFFF;
    v7 = v4 >= (v6 & 0x7FFFFFFFu);
    v8 = v6 & 0x80000000;
    if ( !v7 )
      v8 += 0x80000000;
    v5[2] = v4 | v8;
    return result;
  }
  v2 = *(uint32_t *)off_11DEA0;
  while ( 1 )
  {
    a2 = *(uint32_t *)(a2 + 4);
    if ( **(__int16 **)off_11DEA0 < 0 && !a2 )
      return sub_12F2C8(dword_11DEA8, dword_11DEA4, 1119, v2);
    v2 = *(unsigned __int16 *)(a2 + 16) << 31;
    if ( (*(uint16_t *)(a2 + 16) & 1) != 0 )
      goto LABEL_8;
  }
}

