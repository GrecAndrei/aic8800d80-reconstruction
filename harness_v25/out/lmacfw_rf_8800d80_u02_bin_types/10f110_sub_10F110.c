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

extern uint32_t dword_10F144;
extern uint32_t dword_10F140;
extern uint32_t dword_10F148;

// sub_10F110 @ 0x10f110, size 46 bytes
int  sub_10F110(int a1)
{
  sub_10F064(dword_10F144, 196608, dword_10F140, 1);
  rf_reg_write_wait(dword_10F148, a1 << 15, 1);
  return sub_10F064(1879048192, 1, 1, 1);
}

