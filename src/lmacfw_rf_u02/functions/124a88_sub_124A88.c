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


extern uint32_t off_124AF8;

// set_adv_interval @ 0x124a88, size 110 bytes
int  set_adv_interval(int a1, uint32_t *a2)
{
  int *v3; // r6
  unsigned int v4; // r5
  int v5; // r3
  uint8_t *v6; // r0
  int v7; // r4
  int v8; // r0
  int v9; // r2
  int result; // r0
  int v11; // [sp+4h] [bp-4h]

  if ( a1 <= 2 )
  {
    dispatch_event_handler_1(asc_130144, a2);
    return -1;
  }
  else
  {
    v3 = (int *)off_124AF8;
    v4 = parse_number((uint8_t *)a2[1], nullptr, 0xAu);
    v5 = parse_number((uint8_t *)a2[2], nullptr, 0xAu);
    v6 = (uint8_t *)a2[3];
    v7 = v5;
    v8 = parse_number(v6, nullptr, 0xAu);
    v9 = v8;
    if ( *v3 )
    {
      v11 = v8;
      init_with_stack(0);
      v9 = v11;
    }
    configure_hw_regs(v4, v7, v9);
    dispatch_event_handler_1(asc_130170);
    result = *v3;
    if ( *v3 )
    {
      init_with_stack(result);
      return 0;
    }
  }
  return result;
}
