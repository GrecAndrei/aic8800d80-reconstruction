// sub_10CEC0 @ 0x10cec0, size 34 bytes
int sub_10CEC0()
{
  int v0; // r3
  int result; // r0

  v0 = *(uint32_t *)off_10CEE8 + 4 * (*((unsigned __int8 *)off_10CEE4 + 16) + 136);
  *(uint32_t *)off_10CEEC = 32;
  result = *(uint32_t *)(v0 + 4);
  if ( result )
    return 1;
  *(uint32_t *)off_10CEF0 = 32;
  return result;
}

