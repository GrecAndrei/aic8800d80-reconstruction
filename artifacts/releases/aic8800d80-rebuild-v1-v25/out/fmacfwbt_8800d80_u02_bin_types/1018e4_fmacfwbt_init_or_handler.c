// fmacfwbt_init_or_handler @ 0x1018e4, size 28 bytes
// Doc: fmacfwbt_init_or_handler [unknown]: FMAC BT firmware init/handler stub
// fmacfwbt_init_or_handler [unknown]: FMAC BT firmware init/handler stub
uint32_t * fmacfwbt_init_or_handler(uint32_t *result, uint32_t *a2)
{
  uint32_t *v2; // r3

  v2 = off_101900;
  *(uint32_t *)off_101900 = *result;
  v2[1] = result[1];
  v2[2] = *a2;
  v2[3] = a2[1];
  v2[4] = a2[2];
  v2[5] = a2[3];
  return result;
}

