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

extern uint32_t off_113B04;
extern uint32_t off_113AFC;
extern uint32_t off_113B00;

// rf_load_calibration @ 0x113ae0, size 28 bytes
int  rf_load_calibration(int a1)
{
  uint8_t *v1; // r2
  char v2; // r3

  rf_save_regs(a1);
  v1 = off_113B04;
  v2 = *((uint8_t *)off_113AFC + 352);
  *(uint8_t *)off_113B00 = *((uint8_t *)off_113AFC + 326);
  *v1 = v2;
  return 1;
}

