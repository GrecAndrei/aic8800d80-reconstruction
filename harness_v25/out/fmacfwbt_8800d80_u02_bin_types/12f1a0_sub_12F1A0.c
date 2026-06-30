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

extern uint32_t dword_12F1CC;
extern uint32_t off_12F1D0;

// sub_12F1A0 @ 0x12f1a0, size 42 bytes
int  sub_12F1A0(int a1, uint32_t *a2, int16_t a3, int16_t a4)
{
  sub_12ECB0(dword_12F1CC, *a2);
  *((uint32_t *)off_12F1D0 + 1) = *a2;
  sub_12CC38(1031, a4, a3);
  return 0;
}

