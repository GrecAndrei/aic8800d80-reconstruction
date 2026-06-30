#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

#define LOBYTE(x) ((uint8_t)((x) & 0xFF))
#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))

extern uint32_t off_10CEB4;
extern uint32_t off_10CEBC;
extern uint32_t off_10CEB8;

// rf_init_or_isr @ 0x10ce80, size 52 bytes
// Doc: rf_init_or_isr [rf]: RF register initialization or interrupt service routine
// rf_init_or_isr [rf]: RF register initialization or interrupt service routine
int rf_init_or_isr()
{
  int v0; // r4
  uint32_t *v1; // r2
  int result; // r0

  v0 = *(uint32_t *)off_10CEB4;
  if ( (*(uint32_t *)off_10CEB4 & 0x20) != 0 )
  {
    v1 = off_10CEBC;
    *(uint32_t *)off_10CEB8 = 32;
    *v1 = 32;
    result = irq_nesting_or(0x400000);
  }
  if ( (v0 & 2) != 0 )
  {
    result = irq_nesting_or(0x8000000);
    *(uint32_t *)off_10CEB8 = 2;
  }
  return result;
}

