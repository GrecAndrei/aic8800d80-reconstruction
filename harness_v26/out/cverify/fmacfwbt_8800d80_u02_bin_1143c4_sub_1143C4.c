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

#define dword_1143CC ((uint32_t)0x001672acu)
// sub_1143C4 @ 0x1143c4, size 6 bytes
// Doc: sub_12143C4 [util]: Load and return a pointer to a global config structure (0x1672ac)
// sub_12143C4 [util]: Load and return a pointer to a global config structure (0x1672ac)
int  sub_1143C4(int a1, int a2, int a3)
{
  return sub_12ECB0(dword_1143CC, a2, a3);
}

