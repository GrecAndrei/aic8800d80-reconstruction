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

#define off_10D648 ((uint32_t)0x40032014u)
#define off_10D64C ((uint32_t)0x40032000u)
// mmio_read_u8 @ 0x10d638, size 16 bytes
// Doc: mmio_read_u8 [mmio]: Read a byte from MMIO register at 0x40032000
// mmio_read_u8 [mmio]: Read a byte from MMIO register at 0x40032000
int mmio_read_u8()
{
  while ( (*(uint32_t *)off_10D648 & 1) == 0 )
    ;
  return (uint8_t)*(uint32_t *)off_10D64C;
}

