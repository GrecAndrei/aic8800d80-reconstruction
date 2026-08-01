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

extern uint32_t dword_121FB0;
extern uint32_t dword_121FB4;

// buffer_alloc @ 0x121f38, size 118 bytes
int  buffer_alloc(int a1, uint8_t *a2, uint8_t *a3)
{
  int v6; // r4
  int v8; // r5
  int v9; // r9
  int v10; // r3
  uint8_t *v11; // r3

  v6 = wlc_detach((int *)a1, a2);
  if ( v6 )
    return v6;
  v8 = *(uint8_t *)(a1 + 25);
  v9 = dword_121FB0 + 696 * (uint8_t)*a2;
  *(uint8_t *)(v9 + 669) = 0;
  *(uint16_t *)(v9 + 670) = 0;
  *a3 = rf_set_channel((uint8_t)*a2, v8);
  v10 = *(uint32_t *)(v9 + 44);
  if ( v10 )
    rf_set_channel(*(uint8_t *)(v10 + 35), *(uint8_t *)(a1 + 25));
  v11 = (uint8_t *)(dword_121FB4 + 1320 * v8);
  if ( v11[106] )
    return v6;
  v11[116] = *a2;
  v11[117] = *(uint8_t *)(a1 + 29);
  v11[118] = *(uint8_t *)(a1 + 30);
  return 0;
}

