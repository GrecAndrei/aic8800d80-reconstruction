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

// sub_11428c @ 0x11428c, size 72 bytes
// Doc: rf_fault_dump_n_4aa [rf]: Dump RF fault information and increment counter
// rf_fault_dump_n_4aa [rf]: Dump RF fault information and increment counter
int sub_11428c()
{
  int *v0; // r5
  uint32_t *v1; // r4
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)rf_fault_dump_n_474 = 1;
  }
  v0 = (int *)rf_fault_dump_n_470;
  v1 = rf_fault_handler;
  ++*(uint32_t *)rf_fault_dump_n_470;
  while ( !*v1 )
    ;
  result = cmd_handler_a(*(uint32_t *)rf_state_check_n2d6 + 628);
  *v1 = 1;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)rf_fault_dump_n_474;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

