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

#define dword_119278 ((uint32_t)0x00167d04u)
// sub_11926C @ 0x11926c, size 10 bytes
int  sub_11926C(int a1, int a2)
{
  return *(uint8_t *)(dword_119278 + (a1 | (2 * a2)));
}

