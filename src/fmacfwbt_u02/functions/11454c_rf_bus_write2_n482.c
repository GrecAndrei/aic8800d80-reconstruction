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

extern uint32_t off_114594;
extern uint32_t off_114590;
extern uint32_t off_114598;
extern uint32_t off_1145A0;
extern uint32_t off_11459C;

// rf_bus_write2_n482 @ 0x11454c, size 68 bytes
// Doc: rf_bus_write2_n482 [rf]: RF bus write variant with masked address and MMIO store
// rf_bus_write2_n482 [rf]: RF bus write variant with masked address and MMIO store
int rf_bus_write2_n482()
{
  int v0; // r2
  int v1; // r1
  uint32_t *v2; // r3

  if ( *(uint32_t *)off_114594 )
    v0 = 2048;
  else
    v0 = 4096;
  if ( *(uint32_t *)off_114594 )
    v1 = 1;
  else
    v1 = 2;
  if ( *(uint8_t *)(*(uint32_t *)off_114590 + 6) == 1 )
    *((uint32_t *)off_114598 + 83) &= ~v1;
  v2 = off_1145A0;
  *(uint32_t *)(*(uint32_t *)off_11459C + 8) = 0;
  v2[34] = v0;
  __dsb(0xFu);
  __isb(0xFu);
  return 0;
}

