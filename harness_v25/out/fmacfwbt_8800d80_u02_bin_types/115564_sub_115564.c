// sub_115564 @ 0x115564, size 184 bytes
// Doc: patch_apply_n116 [mac]: Apply firmware patch N116: install handler function pointers and clear boot status bits.
// patch_apply_n116 [mac]: Apply firmware patch N116: install handler function pointers and clear boot status bits.
void __noreturn sub_115564()
{
  uint32_t *v0; // r2
  unsigned int v1; // r3
  int v2; // r1
  char *v3; // r2
  char *v4; // r3
  uint32_t *v5; // r0
  int v6; // t1
  uint32_t *v7; // r2
  int v8; // r0
  int i; // r3
  int v10; // r2
  int v11; // r3
  uint8_t *v12; // r2

  v0 = (uint32_t *)dword_115620;
  if ( dword_115620 < (unsigned int)dword_115624 )
  {
    v1 = ((dword_115624 - 1 - dword_115620) & 0xFFFFFFFC) + 4 + dword_115620;
    do
      *v0++ = 0;
    while ( v0 != (uint32_t *)v1 );
  }
  v2 = dword_115628;
  if ( dword_115628 < (unsigned int)dword_11562C )
  {
    v3 = (char *)off_115630;
    v4 = (char *)off_115630 + ((dword_11562C - 1 - dword_115628) & 0xFFFFFFFC) + 4;
    v5 = (uint32_t *)dword_115628;
    do
    {
      v6 = *(uint32_t *)v3;
      v3 += 4;
      *v5++ = v6;
    }
    while ( v3 != v4 );
  }
  v7 = off_115634;
  v8 = dword_115638;
  *((uint32_t *)off_115634 + 34) |= 0xF00000u;
  v7[2] = v2;
  for ( i = 0; i != 86; ++i )
  {
    v10 = v8 + i;
    *(uint8_t *)(v10 + 768) = -1;
  }
  if ( (unsigned __int16)*(uint32_t *)off_115634 == 49729 )
    *(uint32_t *)off_11563C = 1;
  v11 = HIBYTE(*(uint32_t *)off_115640);
  *(uint8_t *)off_115644 = v11;
  if ( (v11 & 4) != 0 )
  {
    v12 = off_11564C;
    *(uint32_t *)off_115648 = dword_115650;
    *v12 = 26;
  }
  if ( (v11 & 0x10) == 0 )
    *(uint32_t *)off_115654 &= ~0x4000u;
  *(uint8_t *)off_115658 = BYTE2(*(uint32_t *)off_115640);
  sub_1030B0();
  sub_1154E8();
  sub_100478();
}

