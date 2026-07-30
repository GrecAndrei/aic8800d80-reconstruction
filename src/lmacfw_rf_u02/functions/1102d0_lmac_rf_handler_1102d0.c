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

extern uint32_t off_110310;
extern uint32_t off_110314;
extern uint32_t dword_110318;
extern uint32_t off_11031C;

// lmac_rf_handler_1102d0 @ 0x1102d0, size 62 bytes
// Doc: lmac_rf_handler_1102d0 [rf]: LMAC RF handler stub at 0x1102d0
// lmac_rf_handler_1102d0 [rf]: LMAC RF handler stub at 0x1102d0
int lmac_rf_handler_1102d0()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_110310 = 1;
  }
  v0 = (int *)off_110314;
  v1 = dword_110318;
  ++*(uint32_t *)off_110314;
  result = sub_11E7AC(v1);
  if ( result )
    --*(uint32_t *)off_11031C;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_110310;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

