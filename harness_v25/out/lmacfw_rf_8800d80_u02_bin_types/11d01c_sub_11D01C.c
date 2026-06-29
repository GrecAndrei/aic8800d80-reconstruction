// sub_11D01C @ 0x11d01c, size 118 bytes
uint32_t *sub_11D01C()
{
  uint32_t *v0; // r2
  int v1; // r4
  int *v2; // r0
  uint32_t *v3; // r5
  int v4; // r3
  int v5; // r1
  uint32_t *result; // r0
  int *v7; // r3
  int v8; // r3

  if ( **(__int16 **)off_11D094 < 0 && !(*(uint32_t *)off_11D0AC << 28) )
    return (uint32_t *)sub_121960(dword_11D0B4, dword_11D0B0, 213, *(uint32_t *)off_11D0AC);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11D098 = 1;
  }
  v0 = off_11D0A0;
  v1 = *(uint32_t *)off_11D0A0;
  v2 = (int *)off_11D0A4;
  v3 = off_11D0A8;
  v4 = *(uint32_t *)off_11D09C + 25000;
  v5 = *(uint32_t *)off_11D0A0 + 1;
  *(uint32_t *)off_11D0A0 = v5;
  *v2 = v4;
  result = v2 + 8146;
  *v3 = 128;
  *result |= 0x80u;
  *(v3 - 8212) = 0;
  if ( v5 )
  {
    v7 = (int *)off_11D098;
    *v0 = v1;
    v8 = *v7;
    if ( !v1 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}

