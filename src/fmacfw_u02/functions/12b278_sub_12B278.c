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

extern uint32_t off_12B2A8;
extern uint32_t off_12B2AC;

// sub_12B278 @ 0x12b278, size 46 bytes
// Doc: sub_122B278 [mmio]: Read interface state offset 0x16c and invoke sub-handler
// sub_122B278 [mmio]: Read interface state offset 0x16c and invoke sub-handler
int  sub_12B278(int a1)
{
  uint32_t *v1; // r6
  char *v2; // r4
  int result; // r0

  v1 = off_12B2A8;
  v2 = (char *)off_12B2AC;
  v1[1] = sub_12DB60(off_12B2AC, *(uint16_t *)(*(uint32_t *)off_12B2A8 + 364));
  result = sub_12B1A4();
  *(uint32_t *)&v2[-8] = *(uint32_t *)&v2[-12] - 1 + *(uint16_t *)(a1 + 364);
  *((uint32_t *)v2 - 1) = 0;
  return result;
}

