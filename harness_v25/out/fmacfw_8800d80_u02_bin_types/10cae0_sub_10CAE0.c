// sub_10CAE0 @ 0x10cae0, size 182 bytes
int sub_10CAE0()
{
  int v0; // r4
  int result; // r0
  uint32_t *v2; // r2
  uint8_t *v3; // r3
  uint32_t *v4; // r2
  uint32_t *v5; // r2
  uint32_t *v6; // r2

  v0 = *(uint32_t *)off_10CB98;
  if ( (*(uint32_t *)off_10CB98 & 0x20) != 0 )
  {
    v6 = off_10CBA0;
    *(uint32_t *)off_10CBB8 = 32;
    *v6 = 32;
    sub_12D104(0x80000);
  }
  result = v0 << 27;
  if ( (v0 & 0x10) != 0 )
  {
    v5 = off_10CBA0;
    *(uint32_t *)off_10CBB8 = 16;
    *v5 = 16;
    result = sub_12D104(0x100000);
  }
  if ( (v0 & 2) != 0 )
  {
    result = sub_12D104(0x8000000);
    *(uint32_t *)off_10CBB8 = 2;
  }
  if ( (v0 & 0x40000000) != 0 )
  {
    result = sub_1145AC(1);
    *(uint32_t *)off_10CBA0 = 0x40000000;
  }
  if ( v0 < 0 )
  {
    v2 = off_10CBA0;
    *(uint32_t *)off_10CB9C = 0x80000000;
    *v2 = 0x80000000;
  }
  if ( (v0 & 0x20000000) == 0 )
  {
    v3 = off_10CBA4;
    if ( !*(uint8_t *)off_10CBA4 || !*(uint32_t *)off_10CBA8 )
      return result;
LABEL_16:
    v4 = off_10CBAC;
    v3[1] = 1;
    *v4 |= 1u;
    return result;
  }
  v3 = off_10CBA4;
  *(uint32_t *)off_10CBA0 = 0x20000000;
  if ( *v3 )
    goto LABEL_16;
  if ( (*(uint32_t *)off_10CBB0 & dword_10CBB4) == 0x10000 )
    return sub_114574();
  return result;
}

