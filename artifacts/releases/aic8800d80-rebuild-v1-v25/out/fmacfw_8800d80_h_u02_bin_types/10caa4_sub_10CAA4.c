// sub_10CAA4 @ 0x10caa4, size 86 bytes
int sub_10CAA4()
{
  uint32_t *v0; // r4
  int v1; // r0
  int v2; // r3
  int v4; // r3

  v0 = off_10CAFC;
  while ( !*(uint32_t *)off_10CAFC )
    ;
  if ( *(uint32_t *)(*(uint32_t *)off_10CB00 + 612) )
  {
    v1 = sub_12D190(*(uint32_t *)off_10CB00 + 612);
    v2 = **(__int16 **)off_10CB04;
    *v0 = 1;
    if ( v2 >= 0 || v1 )
      return v1 + 20;
  }
  else
  {
    v4 = **(__int16 **)off_10CB04;
    *(uint32_t *)off_10CAFC = 1;
    if ( v4 >= 0 )
      return 20;
  }
  sub_12F32C(dword_10CB0C, dword_10CB08, 1101);
  return 20;
}

