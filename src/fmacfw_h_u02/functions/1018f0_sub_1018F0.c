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

extern uint32_t dword_10191C;
extern uint32_t dword_101920;
extern uint32_t off_101918;

// sub_1018F0 @ 0x1018f0, size 40 bytes
uint64_t * sub_1018F0(uint64_t *result, int a2)
{
  uint64_t *v2; // r4

  v2 = result;
  if ( a2 )
  {
    result = (uint64_t *)sub_12E948(dword_10191C, dword_101920, a2);
    *v2 = *(uint64_t *)((char *)off_101918 + 36);
  }
  else
  {
    *result = *(uint64_t *)((char *)off_101918 + 36);
  }
  return result;
}

