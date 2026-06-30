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

extern uint32_t off_101938;
extern uint32_t dword_101940;
extern uint32_t dword_10193C;

// sub_101924 @ 0x101924, size 18 bytes
int  sub_101924(int a1, int a2, int a3)
{
  int result; // r0

  if ( *(uint32_t *)off_101938 << 28 )
    return sub_12E948(dword_101940, dword_10193C, a3);
  return result;
}

