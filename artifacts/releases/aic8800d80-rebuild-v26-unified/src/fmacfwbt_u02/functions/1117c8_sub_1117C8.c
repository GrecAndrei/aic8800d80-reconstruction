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

extern uint32_t dword_1117FC;

// sub_1117C8 @ 0x1117c8, size 48 bytes
// Doc: rf_bus_mark_nfa_17da [rf]: Mark RF bus state via helper call
// rf_bus_mark_nfa_17da [rf]: Mark RF bus state via helper call
int * sub_1117C8(int a1)
{
  int v2; // r0
  int v3; // r5
  int *result; // r0
  int ( *v5)(uint32_t, uint32_t, int); // r3

  v2 = rf_bus_write_n_1c8 + 16 * (a1 - 1);
  v3 = *(uint8_t *)(v2 + 8);
  result = memset_thunk((int *)v2, 0, 0x10u);
  if ( v3 )
  {
    result = (int *)dword_1117FC;
    v5 = *(int ( **)(uint32_t, uint32_t, int))(dword_1117FC + 4 * a1 + 32);
    if ( v5 )
      return (int *)v5(0, 0, 1);
  }
  return result;
}

