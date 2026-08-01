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

extern uint32_t off_112F34;
extern uint32_t dword_112F38;

// rx_increment_count @ 0x112ed0, size 100 bytes
int  rx_increment_count(int a1, uint16_t *a2)
{
  int v4; // r2
  int v5; // r3
  int v6; // r2

  phy_irq_handler();
  if ( *(uint8_t *)off_112F34 != 4 )
    return 1;
  v4 = a1 - 1;
  if ( (uint8_t)(a1 - 1) > 5u )
    return 2;
  if ( (*((uint32_t *)&REG_4020_0900 + 8 * a1) & 0x8000) == 0 )
    return 5;
  v5 = 32 * v4 + 0x40000000;
  v6 = dword_112F38 + 16 * v4;
  *(uint32_t *)(v6 + 4) = *a2;
  *(uint8_t *)(v6 + 11) = 1;
  *(uint32_t *)(v5 + 2099508) = a2;
  *((uint32_t *)&REG_4020_0900 + 8 * a1) |= 0x84000000;
  return 0;
}

