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

extern uint32_t off_10DBA0;

// irq_prio_set2 @ 0x10db90, size 16 bytes
// Doc: irq_prio_set2 [util]: Set IRQ priority bit in NVIC at 0x40505000+8
// irq_prio_set2 [util]: Set IRQ priority bit in NVIC at 0x40505000+8
int  irq_prio_set2(char a1)
{
  int result; // r0

  result = (1 << a1) | *((uint32_t *)off_10DBA0 + 2);
  *((uint32_t *)off_10DBA0 + 2) = result;
  return result;
}

