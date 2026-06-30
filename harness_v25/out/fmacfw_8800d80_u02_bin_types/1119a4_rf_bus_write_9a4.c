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

extern uint32_t dword_1119D8;

// rf_bus_write_9a4 @ 0x1119a4, size 48 bytes
// Doc: rf_bus_write_9a4 [rf]: Write data to the RF bus
// rf_bus_write_9a4 [rf]: Write data to the RF bus
int * rf_bus_write_9a4(int a1)
{
  int v2; // r0
  int v3; // r5
  int *result; // r0
  int ( *v5)(uint32_t, uint32_t, int); // r3

  v2 = rf_bus_write_n_190 + 16 * (a1 - 1);
  v3 = *(uint8_t *)(v2 + 11);
  result = memset_thunk((int *)v2, 0, 0x10u);
  if ( v3 )
  {
    v5 = *(int ( **)(uint32_t, uint32_t, int))(dword_1119D8 + 4 * (a1 + 13));
    if ( v5 )
      return (int *)v5(0, 0, 1);
  }
  return result;
}

