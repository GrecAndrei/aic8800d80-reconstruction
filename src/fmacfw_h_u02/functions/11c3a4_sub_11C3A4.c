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

extern uint32_t off_11C3B4;

// set_global_config_bytes @ 0x11c3a4, size 16 bytes
uint8_t * set_global_config_bytes(uint8_t *result)
{
  uint8_t *v1; // r3

  v1 = off_11C3B4;
  *((uint8_t *)off_11C3B4 + 164) = *result;
  v1[165] = result[1];
  return result;
}

