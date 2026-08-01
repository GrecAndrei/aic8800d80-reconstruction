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

// timer_entry_clear @ 0x111274, size 48 bytes
// Doc: rf_bus_mark_n102 [rf]: Mark/flag RF bus slot for pending operation
// rf_bus_mark_n102 [rf]: Mark/flag RF bus slot for pending operation
int * timer_entry_clear(int a1)
{
  int v2; // r0
  int v3; // r5
  int *result; // r0
  int ( *v5)(uint32_t, uint32_t, int); // r3

  v2 = rf_bus_reset2_n_60 + 16 * (a1 - 1);
  v3 = *(uint8_t *)(v2 + 8);
  result = sub_100200((int *)v2, 0, 0x10u);
  if ( v3 )
  {
    result = (int *)rf_bus_write_n_1c4;
    v5 = *(int ( **)(uint32_t, uint32_t, int))(rf_bus_write_n_1c4 + 4 * a1 + 32);
    if ( v5 )
      return (int *)v5(0, 0, 1);
  }
  return result;
}

