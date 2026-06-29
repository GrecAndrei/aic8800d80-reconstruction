// log_alloc @ 0x10fe7c, size 62 bytes
// Doc: log_alloc [util]: Allocate a log entry from the log pool if logging is enabled
// log_alloc [util]: Allocate a log entry from the log pool if logging is enabled
uint32_t * log_alloc(char a1)
{
  uint32_t *v2; // r4

  if ( **(uint8_t **)off_10FEBC == 1 )
    v2 = (uint32_t *)sub_110340();
  else
    v2 = sub_10F9E8(dword_10FEC0, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( sub_10FDF4((unsigned int)v2) )
  {
    *((uint8_t *)v2 - 1) = a1;
    return v2;
  }
  sub_10DAE4(dword_10FEC4, v2);
  return v2;
}

