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

extern uint32_t off_125CB4;
extern uint32_t dword_125CB8;
extern uint32_t dword_125CAC;
extern uint32_t dword_125CB0;

// sub_125C68 @ 0x125c68, size 66 bytes
// Doc: sub_1225C68 [util]: Initializes a data structure from global tables
// sub_1225C68 [util]: Initializes a data structure from global tables
int  sub_125C68(int a1)
{
  int v2; // r0
  uint8_t *v3; // r2
  int v4; // r1
  int v5; // r4
  int v6; // r0
  int v7; // r6
  int v8; // r2
  int v9; // r3

  v2 = *(uint8_t *)(a1 + 9);
  v3 = off_125CB4;
  v4 = dword_125CB8;
  v5 = dword_125CAC + 1320 * v2;
  v6 = dword_125CB0 + 620 * v2;
  v7 = *(uint8_t *)(v5 + 107);
  *((uint8_t *)off_125CB4 + 9) = 1;
  v3[10] = 0;
  sub_14380C(v6 + 108, v4 + (v7 << 9), *(uint16_t *)(a1 + 4));
  return sub_125C04(v5, 0, v8, v9);
}

