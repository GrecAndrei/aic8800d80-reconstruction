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

extern uint32_t dword_12D598;
extern uint32_t dword_12D590;
extern uint32_t dword_12D594;
extern uint32_t dword_12D59C;
extern uint32_t dword_12D5A0;

// math_fastpath @ 0x12d520, size 110 bytes
// Doc: math_fastpath [util]: Fast-path math/lookup helper using local stack buffer
// math_fastpath [util]: Fast-path math/lookup helper using local stack buffer
int  math_fastpath(int a1)
{
  int v1; // r5
  uint64_t v3; // r0
  uint64_t v4; // r0
  uint64_t v5; // r0
  uint64_t v6; // r0
  unsigned int v7; // r0
  uint32_t v9[32]; // [sp+0h] [bp-104h] BYREF
  uint8_t v10[132]; // [sp+80h] [bp-84h] BYREF

  v1 = dword_12D598;
  sub_143770(v9, dword_12D598, 128);
  sub_143770(v10, v1 + 128, 128);
  v3 = sub_1429F8(a1);
  v4 = sub_142AA8(v3, HIDWORD(v3), dword_12D590, dword_12D594);
  v5 = sub_142AA8(v4, HIDWORD(v4), 0, dword_12D59C);
  v6 = sub_14273C(v5, HIDWORD(v5), 0, dword_12D5A0);
  v7 = sub_142FDC(v6, HIDWORD(v6));
  return v7 & 0x7F800000
       | ((((v7 & 0x7FFFFF) * (uint64_t)(int)v9[(v7 >> 18) & 0x1F]) >> 23) + *(uint32_t *)&v10[4 * ((v7 >> 18) & 0x1F)]);
}

