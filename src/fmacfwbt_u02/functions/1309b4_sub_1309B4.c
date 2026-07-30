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

extern uint32_t off_1309EC;

// sub_1309B4 @ 0x1309b4, size 56 bytes
int  sub_1309B4(int a1)
{
  uint32_t *v2; // r1
  uint16_t *v3; // r2
  int16_t v4; // r6
  int16_t v5; // r5
  int16_t v6; // r4

  v2 = off_1309EC;
  **(uint8_t **)a1 = -65;
  *(uint8_t *)(*(uint32_t *)a1 + 1) = 12;
  *(uint32_t *)(*(uint32_t *)a1 + 2) = v2[12];
  v3 = *(uint16_t **)a1;
  v4 = *((uint16_t *)v2 + 26);
  v5 = *((uint16_t *)v2 + 27);
  v6 = *((uint16_t *)v2 + 28);
  v3[6] = *((uint16_t *)v2 + 29);
  v3[3] = v4;
  v3[4] = v5;
  v3[5] = v6;
  *(uint32_t *)a1 = v3 + 7;
  return 14;
}

