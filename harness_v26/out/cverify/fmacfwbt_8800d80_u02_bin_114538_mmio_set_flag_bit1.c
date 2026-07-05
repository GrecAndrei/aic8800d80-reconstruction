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

#define off_114548 ((uint32_t)0x0017343cu)
// mmio_set_flag_bit1 @ 0x114538, size 14 bytes
// Doc: mmio_set_flag_bit1 [mmio]: Sets bit 1 in MMIO register at indirect pointer offset +8
// mmio_set_flag_bit1 [mmio]: Sets bit 1 in MMIO register at indirect pointer offset +8
void mmio_set_flag_bit1()
{
  *(uint32_t *)(*(uint32_t *)off_114548 + 8) |= 2u;
}

