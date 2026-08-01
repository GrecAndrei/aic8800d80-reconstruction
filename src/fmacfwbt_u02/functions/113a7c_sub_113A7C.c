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

extern uint32_t off_113AA0;
extern uint32_t off_113A98;
extern uint32_t off_113A9C;

// rf_stat_apply @ 0x113a7c, size 28 bytes
int  rf_stat_apply(int a1)
{
  uint8_t *v1; // r2
  char v2; // r3

  rf_stat_read(a1);
  v1 = off_113AA0;
  v2 = *((uint8_t *)off_113A98 + 352);
  *(uint8_t *)off_113A9C = *((uint8_t *)off_113A98 + 326);
  *v1 = v2;
  return 1;
}

