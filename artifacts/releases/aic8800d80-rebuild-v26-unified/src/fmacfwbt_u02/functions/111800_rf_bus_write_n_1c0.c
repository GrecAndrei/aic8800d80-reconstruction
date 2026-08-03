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

// rf_bus_write_n_1c0 @ 0x111800, size 48 bytes
// Doc: rf_bus_reset2_1812 [rf]: Helper tail-call into bus reset primitive
// rf_bus_reset2_1812 [rf]: Helper tail-call into bus reset primitive
int * rf_bus_write_n_1c0(int a1)
{
  int v2; // r0
  int v3; // r5
  int *result; // r0
  int ( *v5)(uint32_t, uint32_t, int); // r3

  v2 = rf_bus_write2_1830 + 16 * (a1 - 1);
  v3 = *(uint8_t *)(v2 + 11);
  result = memset_thunk((int *)v2, 0, 0x10u);
  if ( v3 )
  {
    v5 = *(int ( **)(uint32_t, uint32_t, int))(rf_bus_write_n_18c + 4 * (a1 + 13));
    if ( v5 )
      return (int *)v5(0, 0, 1);
  }
  return result;
}

