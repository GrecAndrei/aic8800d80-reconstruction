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

extern uint32_t dword_1019C8;
extern uint32_t dword_1019CC;
extern uint32_t off_1019C4;

// sub_10199C @ 0x10199c, size 40 bytes
uint64_t * sub_10199C(uint64_t *result, int a2)
{
  uint64_t *v2; // r4

  v2 = result;
  if ( a2 )
  {
    result = (uint64_t *)sub_12EA88(dword_1019C8, dword_1019CC, a2);
    *v2 = *(uint64_t *)((char *)off_1019C4 + 36);
  }
  else
  {
    *result = *(uint64_t *)((char *)off_1019C4 + 36);
  }
  return result;
}

