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

extern uint32_t off_102BB8;
extern uint32_t off_102BBC;

// sub_102B80 @ 0x102b80, size 56 bytes
unsigned int  sub_102B80(uint8_t a1)
{
  unsigned int *v1; // r1
  unsigned int *v2; // r2
  uint8_t v3; // r0
  unsigned int result; // r0

  v1 = (unsigned int *)off_102BB8;
  v2 = (unsigned int *)off_102BBC;
  *(uint32_t *)off_102BB8 = *(uint32_t *)off_102BB8 & 0xFFFFFF00 | a1;
  *v2 = *v2 & 0xFFFFFF00 | a1;
  v3 = a1 - 3;
  *v1 = *v1 & 0xFFF00FFF | (v3 << 12);
  result = *v2 & 0xFFF00FFF | (v3 << 12);
  *v2 = result;
  return result;
}

