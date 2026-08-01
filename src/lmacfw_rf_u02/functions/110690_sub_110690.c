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

extern uint32_t off_1106C4;
extern uint32_t off_1106C8;

// list_init @ 0x110690, size 52 bytes
int  list_init(int a1)
{
  uint32_t *v1; // r2
  uint32_t *v2; // r1

  v1 = off_1106C4;
  v2 = off_1106C8;
  *(uint32_t *)off_1106C4 = 0;
  v1[1] = 0;
  v1[2] = a1;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = 0;
  *v2 = 0;
  v2[1] = 0;
  v2[4] = 0;
  v2[5] = 0;
  *((uint16_t *)v2 + 6) = 0;
  v2[2] = 0;
  *((uint8_t *)v2 + 14) = 0;
  *((uint16_t *)v2 + 14) = 0;
  v2[6] = 0;
  *((uint8_t *)v2 + 30) = 0;
  tx_irq_handler((int)v1, (int)v2);
  return 1;
}

