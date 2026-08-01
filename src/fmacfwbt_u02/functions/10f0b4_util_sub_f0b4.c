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

extern uint32_t off_10F0E8;
extern uint32_t off_10F0EC;
extern uint32_t dword_10F0F0;
extern uint32_t dword_10F0F4;
extern uint32_t dword_10F0F8;

// check_hw_flag @ 0x10f0b4, size 52 bytes
// Doc: check_hw_flag [util]: Generic utility function
// check_hw_flag [util]: Generic utility function
int check_hw_flag()
{
  uint8_t *v0; // r3
  int result; // r0
  int v2; // r1
  int v3; // r2

  if ( *((uint8_t *)off_10F0E8 + 362) )
  {
    *(uint8_t *)off_10F0EC = 0;
  }
  else
  {
    v0 = off_10F0EC;
    *(uint32_t *)off_10F0EC = dword_10F0F0;
    v2 = dword_10F0F4;
    v3 = dword_10F0F8;
    v0[7] = -62;
    *((uint32_t *)v0 + 2) = 1000;
    *((uint16_t *)v0 + 2) = 1752;
    *((uint32_t *)v0 + 4) = v2;
    *((uint32_t *)v0 + 8) = v3;
    return 1752;
  }
  return result;
}

