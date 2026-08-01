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

extern uint32_t off_101788;
extern uint32_t off_1017D4;
extern uint32_t dword_1017DC;
extern uint32_t dword_1017D8;

// llc_event_loop @ 0x101600, size 390 bytes
void __noreturn llc_event_loop()
{
  if ( **(int16_t **)off_101788 < 0
    && (uint8_t)BYTE2(*(uint32_t *)off_1017D4) + 10 * (HIBYTE(*(uint32_t *)off_1017D4) + 2) != 32 )
  {
    mmio_irq_clear(dword_1017DC, dword_1017D8, 6119);
  }
  clock_start();
}

