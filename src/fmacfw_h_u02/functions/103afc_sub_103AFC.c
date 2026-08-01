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

extern uint32_t off_103B44;
extern uint32_t off_103B48;
extern uint32_t off_103B4C;
extern uint32_t off_103B40;
extern uint32_t dword_103B50;

// rf_calibrate @ 0x103afc, size 66 bytes
int rf_calibrate()
{
  uint32_t *v0; // r0
  uint32_t *v1; // r1
  uint32_t *v2; // r2

  v0 = off_103B44;
  v1 = off_103B48;
  v2 = off_103B4C;
  *(uint32_t *)off_103B40 &= 0xFFFFFA53;
  *v0 &= ~0x20000u;
  *v1 &= ~0x1000000u;
  *v2 &= 0xFFE7FFFF;
  mmio_read32(10);
  return check_feature_flag(0x2000, dword_103B50);
}

