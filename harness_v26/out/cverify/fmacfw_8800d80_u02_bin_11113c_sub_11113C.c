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

#define dword_111158 ((uint32_t)0x7fff0000u)
// sub_11113C @ 0x11113c, size 28 bytes
// Doc: sub_121113C [util]: Pack bitfield value from fields (mask OR shift OR shift31)
// sub_121113C [util]: Pack bitfield value from fields (mask OR shift OR shift31)
uint32_t * sub_11113C(uint32_t *result, int a2, int a3, uint16_t a4, int a5)
{
  result[2] = dword_111158 & result[2] | a4 | (a5 << 31);
  *result = a2;
  result[1] = a3;
  return result;
}

