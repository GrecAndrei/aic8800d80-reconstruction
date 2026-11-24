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


extern uint32_t dword_12D0DC;
extern uint32_t dword_12D0F0;
extern uint32_t off_12D0D4;
extern uint32_t off_12D0D8;
extern uint32_t off_12D0E4;
extern uint32_t off_12D0E8;
extern uint32_t off_12D0F8;

// unknown_func_12cff4 @ 0x12cff4, size 222 bytes
uint32_t *unknown_func_12cff4()
{
  int *v0; // r5
  int v1; // r0
  uint32_t *result; // r0
  char *v3; // r4
  int v4; // r3
  int v5; // r2
  int ( *v6)(uint32_t, char *, uint32_t, uint32_t); // r6
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
  v3 = (char *)result;
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
    v6 = (int ( *)(uint32_t, char *, uint32_t, uint32_t))rx_format_field_parse(
                                                               *((uint16_t *)result + 2),
                                                               *((uint16_t *)result + 3));
    event_dispatch(
      "\x9D\x80Dispatching msg:%x from tsk:%x to tsk:%x\n",
      *((uint16_t *)v3 + 2),
      *((uint16_t *)v3 + 4),
      *((uint16_t *)v3 + 3));
    if ( v6 )
    {
      result = (uint32_t *)v6(
                           *((uint16_t *)v3 + 2),
                           v3 + 12,
                           *((uint16_t *)v3 + 3),
                           *((uint16_t *)v3 + 4));
      if ( result == (uint32_t *)1 )
        goto LABEL_12;
      if ( result == (uint32_t *)2 )
      {
        result = (uint32_t *)cmd_handler_a(dword_12D0F0, v3);
        goto LABEL_12;
      }
      if ( result )
      {
        if ( **(uint16_t **)off_12D0E4 < 0 )
          result = (uint32_t *)mmio_clear_register(off_12D0F8, (int)aKeTaskSchedule, 360);
        goto LABEL_12;
      }
    }
    else
    {
      event_dispatch(
        "\x9A\x80No handler found for msg:%x from tsk:%x to tsk:%x\n",
        *((uint16_t *)v3 + 2),
        *((uint16_t *)v3 + 4),
        *((uint16_t *)v3 + 3));
    }
    result = branch_to_12cbc8(v3);
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
    result = (uint32_t *)unknown_func_12d14c(0x4000000);
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
