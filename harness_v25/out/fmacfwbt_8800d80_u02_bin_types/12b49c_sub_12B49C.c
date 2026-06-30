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

extern uint32_t off_12B4CC;
extern uint32_t off_12B4D0;

// sub_12B49C @ 0x12b49c, size 46 bytes
int  sub_12B49C(int a1)
{
  uint32_t *v1; // r6
  char *v2; // r4
  int result; // r0

  v1 = off_12B4CC;
  v2 = (char *)off_12B4D0;
  v1[1] = sub_12DD88(off_12B4D0, *(uint16_t *)(*(uint32_t *)off_12B4CC + 364));
  result = sub_12B3C8();
  *(uint32_t *)&v2[-8] = *(uint32_t *)&v2[-12] - 1 + *(uint16_t *)(a1 + 364);
  *((uint32_t *)v2 - 1) = 0;
  return result;
}

