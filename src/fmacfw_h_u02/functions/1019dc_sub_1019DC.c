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

extern uint32_t dword_101A0C;
extern uint32_t off_101A10;
extern uint32_t off_101A14;
extern uint32_t off_101A08;

// set_rf_frequency @ 0x1019dc, size 44 bytes
int  set_rf_frequency(int16_t a1)
{
  int v1; // r4
  uint32_t *v2; // r1
  int *v3; // r2
  int result; // r0

  v1 = dword_101A0C;
  v2 = off_101A10;
  v3 = (int *)off_101A14;
  result = a1 & 0x7FF;
  *(uint32_t *)off_101A08 = *(uint32_t *)off_101A08 & dword_101A0C | result;
  *v2 &= v1;
  *v3 = ~(~((unsigned int)*v3 >> 11) << 11);
  return result;
}

