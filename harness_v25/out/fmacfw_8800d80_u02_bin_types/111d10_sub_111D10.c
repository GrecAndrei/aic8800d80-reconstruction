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

extern uint32_t dword_111D3C;

// sub_111D10 @ 0x111d10, size 42 bytes
// Doc: rf_state_check_1d26 [rf]: Check the current state bit of an RF sub-block by index
// rf_state_check_1d26 [rf]: Check the current state bit of an RF sub-block by index
int  sub_111D10(int a1, int a2)
{
  uint32_t *v2; // r0
  int v4; // r0

  if ( a2 )
  {
    if ( a1 == 1 )
      v4 = dword_111D3C;
    else
      v4 = rf_bus_mark_n4bc;
    return (*(uint32_t *)(v4 + 32 * a2) >> 21) & 1;
  }
  else
  {
    if ( a1 == 1 )
      v2 = (uint32_t *)dword_111D3C;
    else
      v2 = (uint32_t *)rf_bus_mark_n4bc;
    return (*v2 >> 21) & 1;
  }
}

