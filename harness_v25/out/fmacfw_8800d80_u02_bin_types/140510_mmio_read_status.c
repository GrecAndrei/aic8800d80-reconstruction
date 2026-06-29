// mmio_read_status @ 0x140510, size 42 bytes
// Doc: mmio_read_status [mmio]: Read status word from global state at offset 0x1948
// mmio_read_status [mmio]: Read status word from global state at offset 0x1948
BOOL mmio_read_status()
{
  int v0; // r5

  v0 = dword_14053C;
  if ( !*(uint32_t *)(dword_14053C + 6472) )
    return 1;
  if ( msg_get_value(0xBu) == 3 )
    return **(uint32_t **)(v0 + 6472) == 0;
  return 0;
}

