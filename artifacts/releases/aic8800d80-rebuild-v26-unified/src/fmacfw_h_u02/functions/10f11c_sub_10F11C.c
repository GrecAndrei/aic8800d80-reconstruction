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

extern uint32_t off_10F150;
extern uint32_t off_10F154;
extern uint32_t dword_10F158;
extern uint32_t dword_10F15C;
extern uint32_t off_10F160;

// sub_10F11C @ 0x10f11c, size 52 bytes
int sub_10F11C()
{
  uint8_t *v0; // r3
  int result; // r0
  int v2; // r1
  void *v3; // r2

  if ( *((uint8_t *)off_10F150 + 362) )
  {
    *(uint8_t *)off_10F154 = 0;
  }
  else
  {
    v0 = off_10F154;
    *(uint32_t *)off_10F154 = dword_10F158;
    v2 = dword_10F15C;
    v3 = off_10F160;
    v0[7] = -62;
    *((uint32_t *)v0 + 2) = 1000;
    *((uint16_t *)v0 + 2) = 1752;
    *((uint32_t *)v0 + 4) = v2;
    *((uint32_t *)v0 + 8) = v3;
    return 1752;
  }
  return result;
}

