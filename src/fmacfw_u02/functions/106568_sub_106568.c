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

extern uint32_t dword_1065F0;
extern uint32_t dword_1065F4;
extern uint32_t dword_1065E8;
extern uint32_t dword_1065EC;

// runtime_helper_div @ 0x106568, size 124 bytes
// Doc: sub_1206568 [util]: Helper: invoke MMIO/set call with relocated constants
// sub_1206568 [util]: Helper: invoke MMIO/set call with relocated constants
int  runtime_helper_div(int a1, int a2, int a3)
{
  uint64_t v5; // r0
  int v6; // r0
  int v7; // r9
  int v8; // r0
  int v9; // r7
  float v10; // r0
  uint64_t v11; // kr00_8
  int v12; // r5

  v5 = int_to_double(a2);
  v6 = double_subtract(v5, HIDWORD(v5), dword_1065F0, dword_1065F4);
  v7 = a1 + 4 * a3;
  v8 = double_to_uint(v6);
  v9 = *(uint32_t *)(v7 + 140);
  v10 = COERCE_FLOAT(free_msg(v8));
  v11 = *(uint64_t *)(a1 + 164);
  v12 = (int)(float)(v10 * 20.0);
  if ( SHIDWORD(v11) < v12 )
  {
    check_status_bits(1, dword_1065E8);
    if ( *(uint32_t *)(a1 + 172) <= v12 )
      goto LABEL_3;
LABEL_5:
    check_status_bits(1, dword_1065EC);
    goto LABEL_3;
  }
  if ( *(uint32_t *)(a1 + 172) > v12 )
    goto LABEL_5;
LABEL_3:
  *(uint32_t *)(v7 + 140) = v9 + v11 - v12;
  return memcpy_from_rodata(a1, a3);
}

