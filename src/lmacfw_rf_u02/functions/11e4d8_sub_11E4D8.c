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


extern uint32_t dword_11E5C0;
extern uint32_t dword_11E5D4;
extern uint32_t off_11E5B8;
extern uint32_t off_11E5BC;
extern uint32_t off_11E5C8;
extern uint32_t off_11E5CC;
extern uint32_t off_11E5DC;

// set_busy_flag @ 0x11e4d8, size 222 bytes
uint32_t *set_busy_flag()
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
    *(uint32_t *)off_11E5B8 = 1;
  }
  v0 = (int *)off_11E5BC;
  v1 = dword_11E5C0;
  ++*(uint32_t *)off_11E5BC;
  result = list_pop_front(v1);
  v3 = (char *)result;
  if ( *v0 )
  {
    v4 = *v0 - 1;
    v5 = *(uint32_t *)off_11E5B8;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v6 = (int ( *)(uint32_t, char *, uint32_t, uint32_t))flash_read_byte(
                                                               *((uint16_t *)result + 2),
                                                               *((uint16_t *)result + 3));
    dispatch_event_handler_1(
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
        result = (uint32_t *)check_kernel_state(dword_11E5D4, v3);
        goto LABEL_12;
      }
      if ( result )
      {
        if ( **(uint16_t **)off_11E5C8 < 0 )
          result = (uint32_t *)flash_ctrl_init(off_11E5DC, (int)aKeTaskSchedule, 360);
        goto LABEL_12;
      }
    }
    else
    {
      dispatch_event_handler_1(
        "\x9A\x80No handler found for msg:%x from tsk:%x to tsk:%x\n",
        *((uint16_t *)v3 + 2),
        *((uint16_t *)v3 + 4),
        *((uint16_t *)v3 + 3));
    }
    result = isr_forward(v3);
  }
LABEL_12:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11E5B8 = 1;
  }
  v7 = *((uint32_t *)off_11E5CC + 1);
  v8 = *v0 + 1;
  *v0 = v8;
  if ( !v7 )
  {
    result = (uint32_t *)enter_critical_section_1(0x4000000);
    v8 = *v0;
  }
  if ( v8 )
  {
    v9 = v8 - 1;
    v10 = *(uint32_t *)off_11E5B8;
    *v0 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}
