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

extern uint32_t dword_12A420;

// sub_12A3E8 @ 0x12a3e8, size 54 bytes
uint8_t * sub_12A3E8(int a1, uint8_t a2)
{
  int v2; // r5
  int v3; // r4
  uint8_t *v4; // r3
  int v5; // r0

  v2 = dword_12A420;
  v3 = *(uint8_t *)(a1 + 1225);
  v4 = (uint8_t *)(dword_12A420 + 140 * v3);
  v5 = v4[113];
  v4[115] = a2;
  v4[114] = 1;
  sub_125B98(v5, 3);
  return sub_1296C4((uint8_t *)(v2 + 140 * v3));
}

