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

extern uint32_t dword_11445C;
extern uint32_t off_114460;
extern uint32_t off_114468;
extern uint32_t off_114464;

// sub_114434 @ 0x114434, size 40 bytes
int  sub_114434(int a1, int a2, int a3)
{
  int result; // r0
  uint8_t *v4; // r3
  uint32_t *v5; // r1

  result = sub_12E948(dword_11445C, a2, a3);
  v4 = off_114460;
  if ( *((uint8_t *)off_114460 + 3) )
  {
    v5 = off_114468;
    *(uint32_t *)off_114464 &= ~8u;
    *v5 &= 0xFFFFFFF0;
    v4[3] = 0;
    return 0;
  }
  return result;
}

