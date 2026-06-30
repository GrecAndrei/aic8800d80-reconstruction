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

extern uint32_t dword_12F3B4;
extern uint32_t dword_12F3B8;
extern uint32_t dword_12F3B0;
extern uint32_t dword_12F3A8;
extern uint32_t dword_12F3AC;

// sub_12F334 @ 0x12f334, size 116 bytes
int  sub_12F334(int a1, int *a2, int16_t a3, int16_t a4)
{
  int v5; // r0
  int v6; // r3
  uint32_t *v7; // r4
  int v9; // r5

  v5 = rf_bus_setup_n3a8(1038, a4, a3, 4u);
  v6 = a2[1];
  v7 = (uint32_t *)v5;
  switch ( v6 )
  {
    case 1:
      sub_12ECB0(dword_12F3B4, *(uint32_t *)(*a2 + 4));
      break;
    case 2:
      sub_12ECB0(dword_12F3B8, *a2);
      break;
    case 3:
      v9 = *a2;
      sub_12ECB0(dword_12F3B0, v9);
      if ( !v9 )
        sub_12F2F0();
      rf_level_apply_80c(1068, 1, v9 << 10);
      break;
    default:
      sub_12ECB0(dword_12F3A8);
      break;
  }
  *v7 = (uint8_t)indirect_call_trampoline();
  sub_12ECB0(dword_12F3AC);
  sub_12CBB4((int)v7);
  return 0;
}

