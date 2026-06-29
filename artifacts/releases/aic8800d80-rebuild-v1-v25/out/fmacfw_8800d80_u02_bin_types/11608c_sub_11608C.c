// sub_11608C @ 0x11608c, size 18 bytes
// Doc: sub_121608C [mac]: Fetch context pointer at offset 0x48 from object
// sub_121608C [mac]: Fetch context pointer at offset 0x48 from object
uint32_t * sub_11608C(int a1)
{
  uint32_t *result; // r0

  result = *(uint32_t **)(a1 + 72);
  if ( result )
  {
    result = (uint32_t *)log_free_dispatch_2(result);
    *(uint32_t *)(a1 + 72) = 0;
  }
  return result;
}

