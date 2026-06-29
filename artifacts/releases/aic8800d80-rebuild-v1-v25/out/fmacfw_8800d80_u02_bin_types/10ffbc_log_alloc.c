// log_alloc @ 0x10ffbc, size 62 bytes
// Doc: log_alloc [util]: Logs allocation event based on debug flag
// log_alloc [util]: Logs allocation event based on debug flag
uint32_t * log_alloc(char a1)
{
  uint32_t *v2; // r4

  if ( **(uint8_t **)off_10FFFC == 1 )
    v2 = (uint32_t *)sub_110480();
  else
    v2 = sub_10FB28(log_free_pool_dispatch2_n320, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( sub_10FF34((unsigned int)v2) )
  {
    *((uint8_t *)v2 - 1) = a1;
    return v2;
  }
  sub_10DC24(rf_fault_dump_n3cc, v2);
  return v2;
}

