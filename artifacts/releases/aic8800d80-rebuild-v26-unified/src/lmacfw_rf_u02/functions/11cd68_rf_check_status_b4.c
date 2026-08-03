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

extern uint32_t off_11CDA0;
extern uint32_t off_11CDA8;
extern uint32_t dword_11CDB0;
extern uint32_t dword_11CDAC;
extern uint32_t off_11CDA4;

// rf_check_status_b4 @ 0x11cd68, size 56 bytes
// Doc: rf_check_status_b4 [rf]: Check RF status flag and branch on zero
// rf_check_status_b4 [rf]: Check RF status flag and branch on zero
int rf_check_status_b4()
{
  int result; // r0

  if ( **(int16_t **)off_11CDA0 < 0 && *(uint32_t *)off_11CDA8 << 28 )
    return sub_121960(dword_11CDB0, dword_11CDAC, 105, *(uint32_t *)off_11CDA8);
  if ( (*(uint32_t *)off_11CDA4 & 0x80) != 0 )
  {
    *(uint32_t *)off_11CDA4 &= ~0x80u;
    return irq_nesting_or(0x2000000);
  }
  return result;
}

