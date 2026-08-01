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

extern uint32_t off_10DB28;
extern uint32_t dword_40504080;

// irq_set_priority @ 0x10dafc, size 42 bytes
// Doc: irq_set_priority [util]: Set NVIC interrupt priority with bounds check
// irq_set_priority [util]: Set NVIC interrupt priority with bounds check
int  irq_set_priority(int result)
{
  uint32_t *v1; // r1

  if ( result <= 7 )
  {
    v1 = off_10DB28;
    dword_40504080[result] &= 0xFFFFFFF0;
    result = (1 << result) | v1[1];
    v1[1] = result;
  }
  return result;
}

