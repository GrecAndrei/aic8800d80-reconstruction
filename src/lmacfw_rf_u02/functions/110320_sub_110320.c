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

extern uint32_t off_110360;
extern uint32_t off_110364;
extern uint32_t dword_110368;
extern uint32_t off_11036C;

// irq_disable_set_flag_preserve @ 0x110320, size 62 bytes
// Doc: sub_1210320 [rf]: Unidentified behavioral routine in lmacfw_rf firmware
// sub_1210320 [rf]: Unidentified behavioral routine in lmacfw_rf firmware
int irq_disable_set_flag_preserve()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_110360 = 1;
  }
  v0 = (int *)off_110364;
  v1 = dword_110368;
  ++*(uint32_t *)off_110364;
  result = check_kernel_state(v1);
  v3 = *v0;
  ++*(uint32_t *)off_11036C;
  if ( v3 )
  {
    v4 = v3 - 1;
    v5 = *(uint32_t *)off_110360;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}

