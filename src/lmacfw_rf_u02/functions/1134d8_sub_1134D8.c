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

extern uint32_t off_1134FC;
extern uint32_t off_1134F4;
extern uint32_t off_1134F8;

// refresh_config_params @ 0x1134d8, size 28 bytes
int  refresh_config_params(int a1)
{
  uint8_t *v1; // r2
  char v2; // r3

  update_hw_config(a1);
  v1 = off_1134FC;
  v2 = *((uint8_t *)off_1134F4 + 352);
  *(uint8_t *)off_1134F8 = *((uint8_t *)off_1134F4 + 326);
  *v1 = v2;
  return 1;
}

