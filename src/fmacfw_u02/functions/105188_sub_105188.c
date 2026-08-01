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

extern uint32_t dword_105228;

// compare_memory_ranges @ 0x105188, size 154 bytes
int  compare_memory_ranges(int a1, int a2, int a3)
{
  float v6; // s14
  uint64_t v8; // r8
  uint64_t v9; // r0
  int v10; // r0
  int v11; // r0
  float v12; // r0
  float v13; // s14
  uint64_t v14; // r8
  uint64_t v15; // r0
  int v16; // r0
  int v17; // r0

  if ( a1 > a2 )
  {
    v14 = int_to_double(a1);
    v15 = int_to_double(a2);
    v16 = double_subtract(v14, HIDWORD(v14), v15, HIDWORD(v15));
    v17 = double_to_uint(v16);
    v12 = COERCE_FLOAT(free_msg(v17));
    v13 = 20.0;
    goto LABEL_6;
  }
  if ( a1 < a2 )
  {
    v8 = int_to_double(a2);
    v9 = int_to_double(a1);
    v10 = double_subtract(v8, HIDWORD(v8), v9, HIDWORD(v9));
    v11 = double_to_uint(v10);
    v12 = COERCE_FLOAT(free_msg(v11));
    v13 = -20.0;
LABEL_6:
    v6 = v12 * v13;
    goto LABEL_4;
  }
  v6 = flt_105224;
LABEL_4:
  *(float *)(a3 + 96) = v6;
  return check_status_bits(1, dword_105228);
}

