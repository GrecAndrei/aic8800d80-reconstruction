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

extern uint32_t off_12D0D4;
extern uint32_t off_12D0D8;
extern uint32_t dword_12D0DC;
extern uint32_t dword_12D0E0;
extern uint32_t dword_12D0F0;
extern uint32_t off_12D0E4;
extern uint32_t dword_12D0F8;
extern uint32_t dword_12D0F4;
extern uint32_t dword_12D0EC;
extern uint32_t off_12D0E8;

// unknown_func_12cff4 @ 0x12cff4, size 222 bytes
int unknown_func_12cff4()
{
  int *v0; // r5
  int v1; // r0
  int result; // r0
  uint16_t *v3; // r4
  int v4; // r3
  int v5; // r2
  int ( *v6)(uint32_t, uint16_t *, uint32_t, uint32_t); // r6
  int v7; // r2
  int v8; // r3
  int v9; // r3
  int v10; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12D0D4 = 1;
  }
  v0 = (int *)off_12D0D8;
  v1 = dword_12D0DC;
  ++*(uint32_t *)off_12D0D8;
  result = mem_word_load(v1);
  v3 = (uint16_t *)result;
  if ( *v0 )
  {
    v4 = *v0 - 1;
    v5 = *(uint32_t *)off_12D0D4;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v6 = (int ( *)(uint32_t, uint16_t *, uint32_t, uint32_t))rx_format_field_parse(
                                                                           *(uint16_t *)(result + 4),
                                                                           *(uint16_t *)(result + 6));
    event_dispatch(dword_12D0E0, v3[2], v3[4]);
    if ( v6 )
    {
      result = v6(v3[2], v3 + 6, v3[3], v3[4]);
      if ( result == 1 )
        goto LABEL_12;
      if ( result == 2 )
      {
        result = cmd_handler_a(dword_12D0F0);
        goto LABEL_12;
      }
      if ( result )
      {
        if ( **(int16_t **)off_12D0E4 < 0 )
          result = mmio_clear_register(dword_12D0F8, dword_12D0F4, 360);
        goto LABEL_12;
      }
    }
    else
    {
      event_dispatch(dword_12D0EC, v3[2], v3[4]);
    }
    result = branch_to_12cbc8((int)v3);
  }
LABEL_12:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12D0D4 = 1;
  }
  v7 = *((uint32_t *)off_12D0E8 + 1);
  v8 = *v0 + 1;
  *v0 = v8;
  if ( !v7 )
  {
    result = unknown_func_12d14c(0x4000000);
    v8 = *v0;
  }
  if ( v8 )
  {
    v9 = v8 - 1;
    v10 = *(uint32_t *)off_12D0D4;
    *v0 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}

