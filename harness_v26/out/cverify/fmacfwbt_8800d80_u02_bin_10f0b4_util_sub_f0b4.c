#include <stdint.h>
#define BYTE1(x) ((uint8_t)(((uint32_t)(x) >> 8) & 0xFFu))
#define BYTE2(x) ((uint8_t)(((uint32_t)(x) >> 16) & 0xFFu))
#define BYTE3(x) ((uint8_t)(((uint32_t)(x) >> 24) & 0xFFu))
#define __noreturn
#define _VF 0
#define _CF 0
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

#define off_10F0E8 ((uint32_t)0x00173224u)
#define off_10F0EC ((uint32_t)0x00182bccu)
#define dword_10F0F0 ((uint32_t)0x03e2d801u)
#define dword_10F0F4 ((uint32_t)0x0012eff1u)
#define dword_10F0F8 ((uint32_t)0x0012efd9u)
// util_sub_f0b4 @ 0x10f0b4, size 52 bytes
// Doc: util_sub_f0b4 [util]: Generic utility function
// util_sub_f0b4 [util]: Generic utility function
int util_sub_f0b4()
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

