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

extern uint32_t off_112CD8;
extern uint32_t dword_112CE8;
extern uint32_t dword_112CDC;
extern uint32_t off_112CE4;
extern uint32_t off_112CE0;

// rf_isr_clear @ 0x112ca8, size 48 bytes
uint8_t * rf_isr_clear(int a1, int a2, int a3)
{
  uint8_t *result; // r0
  uint32_t *v4; // r2

  if ( (*((uint16_t *)off_112CD8 + 89) & 0x4000) != 0 )
    result = read_memory_byte((uint8_t *)dword_112CE8);
  else
    result = (uint8_t *)event_dispatch(dword_112CDC, a2, a3);
  v4 = off_112CE4;
  *(uint8_t *)off_112CE0 = 0;
  v4[896] &= ~1u;
  return result;
}

