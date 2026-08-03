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

extern uint32_t off_101860;
extern uint32_t dword_101868;
extern uint32_t dword_101864;

// sub_10184C @ 0x10184c, size 18 bytes
int  sub_10184C(int a1, int a2, int a3)
{
  int result; // r0

  if ( *(uint32_t *)off_101860 << 28 )
    return sub_12ECB0(dword_101868, dword_101864, a3);
  return result;
}

