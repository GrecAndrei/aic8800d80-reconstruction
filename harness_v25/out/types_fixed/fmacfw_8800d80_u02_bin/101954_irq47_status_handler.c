// irq47_status_handler @ 0x101954, size 36 bytes
// Doc: irq47_status_handler [util]: Reads/clears IRQ47 status register bits
// irq47_status_handler [util]: Reads/clears IRQ47 status register bits
int irq47_status_handler()
{
  char *v0; // r2
  int v1; // r1

  v0 = (char *)off_101978;
  v1 = *(_DWORD *)off_101978;
  *(_DWORD *)off_10197C = *(_DWORD *)off_101978;
  if ( (v1 & 0x1000) == 0 )
    return msg_parse(dword_101980, v1, v0);
  *(_DWORD *)&v0[-8] &= ~0x1000u;
  return irq_nesting_or_d104(16);
}

