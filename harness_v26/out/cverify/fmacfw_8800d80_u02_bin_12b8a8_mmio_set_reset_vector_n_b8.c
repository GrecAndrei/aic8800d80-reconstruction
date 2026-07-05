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

#define off_12B8B8 ((uint32_t)0x40328050u)
// mmio_set_reset_vector_n_b8 @ 0x12b8a8, size 16 bytes
// Doc: mmio_set_reset_vector_n_b8 [mmio]: Write 0x40328050 to MMIO control register and return
// mmio_set_reset_vector_n_b8 [mmio]: Write 0x40328050 to MMIO control register and return
void mmio_set_reset_vector_n_b8()
{
  uint32_t *v0; // r2

  v0 = off_12B8B8;
  *(uint32_t *)off_12B8B8 = 1;
  while ( (uint8_t)*v0 )
    ;
}

