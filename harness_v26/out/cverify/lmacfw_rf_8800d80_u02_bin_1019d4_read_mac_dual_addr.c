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

#define off_1019E8 ((uint32_t)0x4033003cu)
#define off_1019E4 ((uint32_t)0x40330000u)
// read_mac_dual_addr @ 0x1019d4, size 14 bytes
// Doc: read_mac_dual_addr [mmio]: Read two 32-bit words from 0x40330000 and 0x4033003c into output pointers
// read_mac_dual_addr [mmio]: Read two 32-bit words from 0x40330000 and 0x4033003c into output pointers
uint32_t * read_mac_dual_addr(uint32_t *result, uint32_t *a2)
{
  uint32_t *v2; // r3

  v2 = off_1019E8;
  *result = *(uint32_t *)off_1019E4;
  *a2 = *v2;
  return result;
}

