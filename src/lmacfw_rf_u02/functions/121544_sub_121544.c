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

extern uint32_t dword_1215A4;

// sub_121544 @ 0x121544, size 96 bytes
int  sub_121544(int a1, int *a2, int16_t a3, int16_t a4)
{
  int v5; // r0
  uint32_t *v6; // r2
  int *v7; // r5
  int v8; // r3
  int v9; // r0
  int v10; // r2

  v5 = sub_11DDF0(1027, a4, a3, 8u);
  v6 = (uint32_t *)*a2;
  v7 = (int *)v5;
  if ( (((unsigned int)*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
  {
    sub_10F010((int)v6, a2[1], 1);
    v9 = sub_10EFBC(*a2, 1);
    v8 = *a2;
  }
  else
  {
    *v6 = a2[1];
    v8 = *a2;
    v9 = *(uint32_t *)*a2;
  }
  v7[1] = v9;
  v10 = a2[1];
  *v7 = v8;
  sub_11F504(dword_1215A4, v10);
  sub_11DE50((int)v7);
  return 0;
}

