// sub_11C7A4 @ 0x11c7a4, size 44 bytes
// Doc: sub_121C7A4 [unknown]: Load 32-bit value from struct offset 0x44
// sub_121C7A4 [unknown]: Load 32-bit value from struct offset 0x44
int  sub_11C7A4(int a1, int a2)
{
  int v2; // r3

  v2 = *(uint32_t *)(a1 + 68);
  if ( v2 && (*(uint16_t *)(v2 + 8) & 0x200) != 0 )
    return *((uint32_t *)off_11C7D0 + 43);
  if ( *(int *)(*(uint32_t *)(a1 + 44) + 60) >= 0 )
    return *(uint32_t *)(a2 + 580);
  return (*(unsigned __int8 *)(a2 + 309) << 9) | 0x8007;
}

