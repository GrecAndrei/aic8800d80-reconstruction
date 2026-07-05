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

#define off_10D470 ((uint32_t)0x40501000u)
#define off_10D478 ((uint32_t)0xe000e100u)
#define off_10D474 ((uint32_t)0xe000ed00u)
#define dword_10D47C ((uint32_t)0x0012d405u)
// timer_init @ 0x10d42c, size 68 bytes
// Doc: timer_init [util]: Initialize firmware timer subsystem
// timer_init [util]: Initialize firmware timer subsystem
int timer_init()
{
  unsigned int *v0; // r2
  unsigned int v1; // r3
  int result; // r0
  uint32_t *v3; // r3

  v0 = (unsigned int *)off_10D470;
  v1 = *(uint32_t *)off_10D470;
  if ( (*(uint32_t *)off_10D470 & 1) == 0 )
  {
    v1 = v1 & 0xFFFFFCFE | 0x101;
    result = 17;
    *((uint32_t *)off_10D470 + 4) = 0;
    v0[5] = 0;
    v0[1] = 17;
    *v0 = v1;
  }
  if ( (v1 & 0x4000) == 0 )
    *(uint32_t *)off_10D470 = v1 | 0x4040;
  v3 = off_10D478;
  *(uint32_t *)(*((uint32_t *)off_10D474 + 2) + 148) = dword_10D47C;
  *v3 = 0x200000;
  return result;
}

