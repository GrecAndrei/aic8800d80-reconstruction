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

extern uint32_t dword_11C440;
extern uint32_t off_11C444;

// sub_11C410 @ 0x11c410, size 46 bytes
unsigned int * sub_11C410(unsigned int *result)
{
  int v1; // r2

  v1 = *(uint16_t *)(dword_11C440 + 1320 * *((uint8_t *)result + 28) + 1222);
  if ( v1 != 1023 && *((uint8_t *)off_11C444 + 361) != 2 )
    return sub_11AF90((unsigned int *)(result[17] + 4), *(uint32_t *)(result[17] + 40), v1);
  return result;
}

