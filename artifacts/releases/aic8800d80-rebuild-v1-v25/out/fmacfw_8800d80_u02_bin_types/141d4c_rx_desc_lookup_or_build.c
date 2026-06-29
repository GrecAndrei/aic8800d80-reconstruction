// rx_desc_lookup_or_build @ 0x141d4c, size 66 bytes
// Doc: rx_desc_lookup_or_build [rx]: Compute RX descriptor table entry via multiply by 0x528
// rx_desc_lookup_or_build [rx]: Compute RX descriptor table entry via multiply by 0x528
int  rx_desc_lookup_or_build(int a1, int a2)
{
  int v3; // r5
  int v4; // r0
  int v5; // r2

  v3 = *(uint32_t *)(a1 + 24)
     - 400
     - *(uint32_t *)(a1 + 48) * a2
     - *(uint32_t *)(dword_141D90 + 1320 * *(unsigned __int8 *)(a1 + 47) + 40);
  v4 = sub_12BE40();
  v5 = *((uint32_t *)off_141D94 + 4);
  *(uint32_t *)(a1 + 56) = dword_141D98;
  return timestamp_update(a1 + 52, v5 + v3 - v4);
}

