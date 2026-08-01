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

extern uint32_t off_12D2FC;
extern uint32_t off_12D300;
extern uint32_t dword_12D304;
extern uint32_t dword_12D308;
extern uint32_t dword_12D318;
extern uint32_t off_12D30C;
extern uint32_t dword_12D320;
extern uint32_t dword_12D31C;
extern uint32_t dword_12D314;
extern uint32_t off_12D310;

// set_system_flag @ 0x12d21c, size 222 bytes
int set_system_flag()
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
    *(uint32_t *)off_12D2FC = 1;
  }
  v0 = (int *)off_12D300;
  v1 = dword_12D304;
  ++*(uint32_t *)off_12D300;
  result = list_pop_front(v1);
  v3 = (uint16_t *)result;
  if ( *v0 )
  {
    v4 = *v0 - 1;
    v5 = *(uint32_t *)off_12D2FC;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v6 = (int ( *)(uint32_t, uint16_t *, uint32_t, uint32_t))hci_cmd_send_vendor(
                                                                           *(uint16_t *)(result + 4),
                                                                           *(uint16_t *)(result + 6));
    ke_event_schedule(dword_12D308, v3[2], v3[4]);
    if ( v6 )
    {
      result = v6(v3[2], v3 + 6, v3[3], v3[4]);
      if ( result == 1 )
        goto LABEL_12;
      if ( result == 2 )
      {
        result = check_abort_flag(dword_12D318);
        goto LABEL_12;
      }
      if ( result )
      {
        if ( **(int16_t **)off_12D30C < 0 )
          result = mmio_irq_clear(dword_12D320, dword_12D31C, 360);
        goto LABEL_12;
      }
    }
    else
    {
      ke_event_schedule(dword_12D314, v3[2], v3[4]);
    }
    result = jump_to_tx_entry((int)v3);
  }
LABEL_12:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12D2FC = 1;
  }
  v7 = *((uint32_t *)off_12D310 + 1);
  v8 = *v0 + 1;
  *v0 = v8;
  if ( !v7 )
  {
    result = set_system_flag_2(0x4000000);
    v8 = *v0;
  }
  if ( v8 )
  {
    v9 = v8 - 1;
    v10 = *(uint32_t *)off_12D2FC;
    *v0 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}

