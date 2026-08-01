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

extern uint32_t off_1174E8;
extern uint32_t off_1174E4;

// gpio_set_bit10 @ 0x1174b8, size 44 bytes
// Doc: sub_12174B8 [mmio]: Modify MMIO register bits via masked read-modify-write
// sub_12174B8 [mmio]: Modify MMIO register bits via masked read-modify-write
unsigned int  gpio_set_bit10(int a1)
{
  unsigned int *v1; // r1
  unsigned int result; // r0

  v1 = (unsigned int *)off_1174E8;
  *(uint32_t *)off_1174E4 = (a1 << 10) & 0x400 | *(uint32_t *)off_1174E4 & 0xFFFFFBFF;
  result = (a1 << 19) & 0x80000 | *v1 & 0xFFF7FFFF;
  *v1 = result;
  return result;
}

