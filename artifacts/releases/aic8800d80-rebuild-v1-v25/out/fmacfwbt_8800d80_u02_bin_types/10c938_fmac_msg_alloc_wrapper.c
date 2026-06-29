// fmac_msg_alloc_wrapper @ 0x10c938, size 182 bytes
// Doc: fmac_msg_alloc_wrapper [util]: Thin wrapper allocating/processing an fmac message
// fmac_msg_alloc_wrapper [util]: Thin wrapper allocating/processing an fmac message
int fmac_msg_alloc_wrapper()
{
  int v0; // r4
  int result; // r0
  uint32_t *v2; // r2
  uint8_t *v3; // r3
  uint32_t *v4; // r2
  uint32_t *v5; // r2
  uint32_t *v6; // r2

  v0 = *(uint32_t *)off_10C9F0;
  if ( (*(uint32_t *)off_10C9F0 & 0x20) != 0 )
  {
    v6 = off_10C9F8;
    *(uint32_t *)off_10CA10 = 32;
    *v6 = 32;
    irq_nesting_or(0x80000);
  }
  result = v0 << 27;
  if ( (v0 & 0x10) != 0 )
  {
    v5 = off_10C9F8;
    *(uint32_t *)off_10CA10 = 16;
    *v5 = 16;
    result = irq_nesting_or(0x100000);
  }
  if ( (v0 & 2) != 0 )
  {
    result = irq_nesting_or(0x8000000);
    *(uint32_t *)off_10CA10 = 2;
  }
  if ( (v0 & 0x40000000) != 0 )
  {
    result = sub_114408(1);
    *(uint32_t *)off_10C9F8 = 0x40000000;
  }
  if ( v0 < 0 )
  {
    v2 = off_10C9F8;
    *(uint32_t *)off_10C9F4 = 0x80000000;
    *v2 = 0x80000000;
  }
  if ( (v0 & 0x20000000) == 0 )
  {
    v3 = off_10C9FC;
    if ( !*(uint8_t *)off_10C9FC || !*(uint32_t *)off_10CA00 )
      return result;
LABEL_16:
    v4 = off_10CA04;
    v3[1] = 1;
    *v4 |= 1u;
    return result;
  }
  v3 = off_10C9FC;
  *(uint32_t *)off_10C9F8 = 0x20000000;
  if ( *v3 )
    goto LABEL_16;
  if ( (*(uint32_t *)off_10CA08 & dword_10CA0C) == 0x10000 )
    return sub_1143D0();
  return result;
}

