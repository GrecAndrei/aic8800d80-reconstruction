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

extern uint32_t dword_10EF4C;

// rf_reg_write_masked @ 0x10ef38, size 18 bytes
// Doc: rf_reg_write_masked [rf]: Masked RF register write utility (stub/leaf)
// rf_reg_write_masked [rf]: Masked RF register write utility (stub/leaf)
int  rf_reg_write_masked(int a1)
{
  return sub_10EE2C(dword_10EF4C, (a1 << 11) & 0xF800, 63488, 1);
}

