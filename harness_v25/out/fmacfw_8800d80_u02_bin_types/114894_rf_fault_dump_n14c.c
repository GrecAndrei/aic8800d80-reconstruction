// rf_fault_dump_n14c @ 0x114894, size 48 bytes
// Doc: rf_fault_dump_n14c [rf]: Dumps RF register state on radio fault detection
// rf_fault_dump_n14c [rf]: Dumps RF register state on radio fault detection
int  rf_fault_dump_n14c(uint8_t *a1)
{
  unsigned int v2; // r0
  char v4; // r3

  v2 = MEMORY[0x1FC](6);
  if ( HIBYTE(v2) )
  {
    *a1 = HIBYTE(v2);
    return 0;
  }
  else
  {
    v4 = BYTE2(v2);
    if ( !HIWORD(v2) )
      v4 = 0;
    *a1 = v4;
    if ( HIWORD(v2) )
      return 1;
    else
      return 2;
  }
}

