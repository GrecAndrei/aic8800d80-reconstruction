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

extern uint32_t off_1009D4;
extern uint32_t dword_1009D8;

// sdio_irq_enable @ 0x1009a0, size 52 bytes
int  sdio_irq_enable(int a1, unsigned int a2)
{
  unsigned int *v2; // r5
  int v3; // r0
  unsigned int v4; // r4
  int result; // r0
  unsigned int v6; // [sp+4h] [bp-8h] BYREF

  v2 = (unsigned int *)off_1009D4;
  v3 = mmio_poll(a1, a2, &v6);
  v4 = *v2;
  *v2 |= 0x4000000u;
  result = memcpy_opt(v3, dword_1009D8, 96, v6);
  *v2 = v4 & 0xFBFFFFFF;
  return result;
}

