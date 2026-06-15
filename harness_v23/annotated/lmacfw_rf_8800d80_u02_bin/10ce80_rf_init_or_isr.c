// v23 annotated: rf_init_or_isr @ 0x10ce80
// Original: 10ce80_rf_init_or_isr.c
// Primary struct: <unclustered>
//
// rf_init_or_isr @ 0x10ce80, size 52 bytes
// Doc: rf_init_or_isr [rf]: RF register initialization or interrupt service routine
// rf_init_or_isr [rf]: RF register initialization or interrupt service routine
int rf_init_or_isr()
{
  int v0; // r4
  _DWORD *v1; // r2
  int result; // r0

  v0 = *(_DWORD *)off_10CEB4;
  if ( (*(_DWORD *)off_10CEB4 & 0x20) != 0 )
  {
    v1 = off_10CEBC;
    *(_DWORD *)off_10CEB8 = 32;
    *v1 = 32;
    result = irq_nesting_or(0x400000);
  }
  if ( (v0 & 2) != 0 )
  {
    result = irq_nesting_or(0x8000000);
    *(_DWORD *)off_10CEB8 = 2;
  }
  return result;
}

