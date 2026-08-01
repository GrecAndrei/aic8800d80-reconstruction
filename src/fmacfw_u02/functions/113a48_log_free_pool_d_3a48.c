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

// assert_error @ 0x113a48, size 54 bytes
// Doc: rf_cmd_process_n4f6 [rf]: Process incoming RF control command
// rf_cmd_process_n4f6 [rf]: Process incoming RF control command
int assert_error()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)rf_msg_process_body_n_1c8 = 1;
  }
  v0 = (int *)rf_msg_process_body_n_1c4;
  v1 = rf_msg_process_body_n_1c0;
  ++*(uint32_t *)rf_msg_process_body_n_1c4;
  result = cmd_handler_a(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)rf_msg_process_body_n_1c8;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

