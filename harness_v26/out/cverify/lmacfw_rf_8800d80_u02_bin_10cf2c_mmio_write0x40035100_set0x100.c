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

#define off_10CF38 ((uint32_t)0x40035100u)
// mmio_write0x40035100_set0x100 @ 0x10cf2c, size 10 bytes
// Doc: mmio_write0x40035100_set0x100 [mmio]: Write 0x100 to MMIO register 0x40035100 then return
// mmio_write0x40035100_set0x100 [mmio]: Write 0x100 to MMIO register 0x40035100 then return
void mmio_write0x40035100_set0x100()
{
  *(uint32_t *)off_10CF38 = 256;
}

