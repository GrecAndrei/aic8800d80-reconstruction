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

extern uint32_t off_10D798;

// nvic_set_priority @ 0x10d784, size 20 bytes
// Doc: sub_120D784 [util]: Trigger CPU interrupt via NVIC (writes 0x8000 to ICSR with DSB/ISB barriers)
// sub_120D784 [util]: Trigger CPU interrupt via NVIC (writes 0x8000 to ICSR with DSB/ISB barriers)
void nvic_set_priority()
{
  *((uint32_t *)off_10D798 + 32) = 0x8000;
  __dsb(0xFu);
  __isb(0xFu);
}

