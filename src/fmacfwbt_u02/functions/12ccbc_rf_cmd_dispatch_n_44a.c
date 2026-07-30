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

extern uint32_t dword_12CCFC;
extern uint32_t off_12CD00;

// rf_cmd_dispatch_n_44a @ 0x12ccbc, size 64 bytes
// Doc: message_dispatch_n12e [ipc]: Message dispatch entry storing zeroed pair into out struct
// message_dispatch_n12e [ipc]: Message dispatch entry storing zeroed pair into out struct
uint32_t *rf_cmd_dispatch_n_44a()
{
  uint32_t *result; // r0
  uint32_t *v1; // r2
  int v2; // r1
  int v3; // r4
  unsigned int v4; // r3
  int *v5; // r3
  int v6; // r3

  result = (uint32_t *)(dword_12CCFC & 0xFFFFFFFC);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12CD00 = 1;
  }
  v1 = message_dispatch_n150;
  v2 = *(uint32_t *)message_dispatch_n150;
  v3 = *(uint32_t *)message_dispatch_n150 + 1;
  v4 = (message_dispatch_n154 & 0xFFFFFFFC) - (uint32_t)result;
  *(uint32_t *)message_dispatch_n150 = v3;
  *result = 0;
  result[1] = v4;
  if ( v3 )
  {
    v5 = (int *)off_12CD00;
    *v1 = v2;
    v6 = *v5;
    if ( !v2 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}

