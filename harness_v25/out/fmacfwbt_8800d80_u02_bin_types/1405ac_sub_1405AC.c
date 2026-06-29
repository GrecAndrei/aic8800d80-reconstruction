// sub_1405AC @ 0x1405ac, size 42 bytes
BOOL sub_1405AC()
{
  int v0; // r5

  v0 = dword_1405D8;
  if ( !*(uint32_t *)(dword_1405D8 + 6472) )
    return 1;
  if ( msg_get_value(0xBu) == 3 )
    return **(uint32_t **)(v0 + 6472) == 0;
  return 0;
}

