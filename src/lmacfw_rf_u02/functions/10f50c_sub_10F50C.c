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

extern uint32_t off_10F540;
extern uint32_t off_10F544;
extern uint32_t dword_10F548;
extern uint32_t off_10F54C;
extern uint32_t dword_10F550;

// rf_init @ 0x10f50c, size 52 bytes
int rf_init()
{
  uint8_t *v0; // r3
  int result; // r0
  void *v2; // r1
  int v3; // r2

  if ( *((uint8_t *)off_10F540 + 362) )
  {
    *(uint8_t *)off_10F544 = 0;
  }
  else
  {
    v0 = off_10F544;
    *(uint32_t *)off_10F544 = dword_10F548;
    v2 = off_10F54C;
    v3 = dword_10F550;
    v0[7] = -62;
    *((uint32_t *)v0 + 2) = 1000;
    *((uint16_t *)v0 + 2) = 1752;
    *((uint32_t *)v0 + 4) = v2;
    *((uint32_t *)v0 + 8) = v3;
    return 1752;
  }
  return result;
}

