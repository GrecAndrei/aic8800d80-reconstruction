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

extern uint32_t off_10194C;
extern uint32_t off_101950;

// sub_101934 @ 0x101934, size 24 bytes
int  sub_101934(int result, int a2, int a3)
{
  if ( (*(uint32_t *)off_10194C & 8) != 0 )
  {
    result = sub_11ED58(result, a2, a3, *(uint32_t *)off_10194C << 28);
    *(uint32_t *)off_101950 = 8;
  }
  return result;
}

