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

extern uint32_t off_112B34;
extern uint32_t dword_112B44;
extern uint32_t dword_112B38;
extern uint32_t off_112B40;
extern uint32_t off_112B3C;

// ke_wait_event_b @ 0x112b04, size 48 bytes
uint8_t * ke_wait_event_b(int a1, int a2, int a3)
{
  uint8_t *result; // r0
  uint32_t *v4; // r2

  if ( (*((uint16_t *)off_112B34 + 89) & 0x4000) != 0 )
    result = uart_puts((uint8_t *)dword_112B44);
  else
    result = (uint8_t *)ke_event_schedule(dword_112B38, a2, a3);
  v4 = off_112B40;
  *(uint8_t *)off_112B3C = 0;
  v4[896] &= ~1u;
  return result;
}

