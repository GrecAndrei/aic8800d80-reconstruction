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

#define off_101A98 ((uint32_t)0x00101a98u)
// chip_revision_get @ 0x101a88, size 14 bytes
// Doc: chip_revision_get [util]: Reads chip revision field (bits 8-11) from ID register and returns (val-1)
// chip_revision_get [util]: Reads chip revision field (bits 8-11) from ID register and returns (val-1)
int chip_revision_get()
{
  return (uint8_t)((BYTE1(*(uint32_t *)off_101A98) & 0xF) - 1);
}

