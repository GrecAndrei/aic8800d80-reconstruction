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

extern uint32_t dword_12A744;
extern uint32_t dword_12A748;

// bt_dev_check_ready @ 0x12a6e8, size 90 bytes
uint8_t * bt_dev_check_ready(int a1, int a2)
{
  uint8_t *result; // r0
  int v3; // r3
  int v4; // r4
  uint8_t *v5; // r2
  int v6; // r5
  uint8_t *v7; // r4

  result = (uint8_t *)(dword_12A744 + 1320 * a1);
  if ( result[1224] && result[106] == 2 )
  {
    v3 = result[1225];
    v4 = dword_12A748;
    v5 = (uint8_t *)(dword_12A748 + 140 * v3);
    v6 = v5[132];
    v5[135] = a2 != 0;
    v7 = (uint8_t *)(v4 + 140 * v3);
    if ( v6 )
      set_flag_byte(v5[113], 3);
    return state_machine_step(v7);
  }
  return result;
}

