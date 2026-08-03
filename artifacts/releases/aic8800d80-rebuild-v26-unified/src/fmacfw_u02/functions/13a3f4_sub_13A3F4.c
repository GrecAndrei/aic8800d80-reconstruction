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

extern uint32_t dword_13A454;
extern uint32_t off_13A458;
extern uint32_t dword_13A45C;

// sub_13A3F4 @ 0x13a3f4, size 94 bytes
int  sub_13A3F4(int a1, int a2, int16_t a3)
{
  int v3; // r4
  char v5; // r5
  int *v7; // r0
  int *v8; // r6
  uint32_t *v9; // r3
  int v10; // r3
  int v11; // r2

  v3 = a1 + 4 * a2;
  if ( *(uint32_t *)(v3 + 408) )
    return 0;
  v5 = a2;
  v7 = rf_bus_mark_n100_d2d0(dword_13A454);
  v8 = v7;
  if ( !v7 )
    return 0;
  memset_thunk(v7, 0, 0x124u);
  v9 = off_13A458;
  *((uint8_t *)v8 + 10) = a3 & 0x3F;
  *((uint8_t *)v8 + 12) = v5;
  v10 = v9[4];
  v11 = dword_13A45C;
  *((uint16_t *)v8 + 4) = a3;
  v8[69] = v11;
  v8[70] = (int)v8;
  v8[1] = v10;
  *(uint32_t *)(v3 + 408) = v8;
  timestamp_update((int)(v8 + 68), v10 + 50000);
  return 1;
}

