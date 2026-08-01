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

extern uint32_t off_12BA00;
extern uint32_t off_12BA04;
extern uint32_t off_12BA08;

// rf_irq_clear @ 0x12b9e0, size 32 bytes
void *rf_irq_clear()
{
  void *result; // r0
  uint32_t *v1; // r1
  uint32_t *v2; // r2

  result = off_12BA00;
  v1 = off_12BA04;
  v2 = off_12BA08;
  *(uint32_t *)off_12BA00 &= ~0x80000000;
  *v1 &= ~0x80000000;
  *v2 &= ~0x80000000;
  return result;
}

