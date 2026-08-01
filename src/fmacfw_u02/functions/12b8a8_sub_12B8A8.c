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

extern uint32_t off_12B8B8;

// mmio_write_one @ 0x12b8a8, size 16 bytes
void mmio_write_one()
{
  uint32_t *v0; // r2

  v0 = off_12B8B8;
  *(uint32_t *)off_12B8B8 = 1;
  while ( (uint8_t)*v0 )
    ;
}

