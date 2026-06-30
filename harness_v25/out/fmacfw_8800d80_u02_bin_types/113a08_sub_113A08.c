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

// sub_113A08 @ 0x113a08, size 52 bytes
// Doc: rf_cmd_process_n4ca [rf]: Process RF command handler (n4ca variant)
// rf_cmd_process_n4ca [rf]: Process RF command handler (n4ca variant)
int sub_113A08()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)rf_cmd_process_n4e4 = 1;
  }
  v0 = (int *)rf_cmd_process_3a40;
  v1 = rf_cmd_process_n4ec;
  ++*(uint32_t *)rf_cmd_process_3a40;
  result = rf_bus_mark_n100_d2d0(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)rf_cmd_process_n4e4;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

