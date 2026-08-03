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

extern uint32_t dword_123190;

// sub_12315C @ 0x12315c, size 50 bytes
int  sub_12315C(int a1, int a2, int a3, int a4)
{
  uint8_t *v4; // r4
  int v5; // r1
  int v6; // r3

  v4 = (uint8_t *)sub_12C92C(129, a4, a3, 64);
  v5 = dword_123190;
  *v4 = 0;
  sub_143770(v4 + 1, v5, 36);
  v6 = (uint8_t)(*v4 + 36);
  *v4 = v6;
  v4[v6 + 1] = 0;
  sub_12C98C(v4);
  return 0;
}

