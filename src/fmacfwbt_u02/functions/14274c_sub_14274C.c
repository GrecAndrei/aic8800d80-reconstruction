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

extern uint32_t dword_1427C4;
extern uint32_t dword_1427C8;
extern uint32_t dword_1427C0;

// float_to_i24 @ 0x14274c, size 114 bytes
int  float_to_i24(int a1)
{
  int v1; // r5
  unsigned int v3; // r7
  int v4; // r6
  int v5; // r7
  int v6; // r0
  int v8; // r0

  v1 = (uint8_t)((unsigned int)a1 >> 23) - 127;
  v3 = a1 & 0x7FFFFFFF;
  if ( v1 > 22 )
  {
    if ( v3 >= 0x7F800000 )
      return double_add(a1, a1);
    return a1;
  }
  v4 = a1;
  if ( v1 < 0 )
  {
    v8 = double_add(a1, dword_1427C4);
    if ( double_less_than(v8, 0) )
    {
      if ( a1 >= 0 )
        return 0;
      if ( v3 )
        return dword_1427C8;
    }
    return a1;
  }
  v5 = dword_1427C0 >> v1;
  if ( (a1 & (dword_1427C0 >> v1)) == 0 )
    return a1;
  v6 = double_add(a1, dword_1427C4);
  if ( !double_less_than(v6, 0) )
    return a1;
  if ( a1 < 0 )
    v4 += 0x800000 >> v1;
  return v4 & ~v5;
}

