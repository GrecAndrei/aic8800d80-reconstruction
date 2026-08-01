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

extern uint32_t off_11DC48;
extern uint32_t dword_11DC34;
extern uint32_t dword_11DC3C;
extern uint32_t dword_11DC38;
extern uint32_t dword_11DC40;
extern uint32_t off_11DC1C;
extern uint32_t off_11DC4C;
extern uint32_t off_11DC50;
extern uint32_t dword_11DC24;
extern uint32_t dword_11DC20;
extern uint32_t dword_11DC44;
extern uint32_t dword_11DC2C;
extern uint32_t off_11DC28;
extern uint32_t dword_11DC30;

// ke_event_loop @ 0x11dafc, size 288 bytes
// Doc: ke_event_loop [util]: Schedule a relative timer with callback and argument
// ke_event_loop [util]: Schedule a relative timer with callback and argument
int  ke_event_loop(int a1, int a2, unsigned int a3)
{
  int16_t **v3; // r11
  int *v7; // r8
  uint32_t *v8; // r10
  int v9; // r6
  int v10; // r4
  int v11; // r2
  int v12; // r0
  unsigned int v13; // r5
  int result; // r0
  int v15; // r3
  int v16; // r2
  int v17; // r0

  v3 = (int16_t **)off_11DC48;
  if ( **(int16_t **)off_11DC48 < 0 )
  {
    if ( a3 )
    {
      if ( a3 > dword_11DC34 )
        flash_ctrl_init(dword_11DC3C, dword_11DC38, 148);
    }
    else
    {
      flash_ctrl_init(dword_11DC40, dword_11DC38, 147);
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11DC1C = 1;
  }
  v7 = (int *)off_11DC4C;
  v8 = off_11DC50;
  v9 = *((uint32_t *)off_11DC50 + 5);
  ++*(uint32_t *)off_11DC4C;
  if ( v9 )
    v9 = *(uint16_t *)(v9 + 4) == a1 && *(uint16_t *)(v9 + 6) == a2;
  v10 = co_list_process(dword_11DC24, dword_11DC20, a2 | (a1 << 16));
  if ( !v10 )
  {
    v17 = align_size_plus4(12);
    v10 = v17;
    if ( **v3 < 0 && !v17 )
      flash_ctrl_init(dword_11DC44, dword_11DC38, 165);
    *(uint16_t *)(v10 + 4) = a1;
    *(uint16_t *)(v10 + 6) = a2;
  }
  v11 = dword_11DC2C;
  v12 = dword_11DC24;
  v13 = a3 + *((uint32_t *)off_11DC28 + 4);
  *(uint32_t *)(v10 + 8) = v13;
  result = list_foreach(v12, v10, v11);
  if ( v9 )
  {
    v10 = v8[5];
    if ( !v10 )
      goto LABEL_10;
LABEL_15:
    result = ke_enter_critical(dword_11DC30, *(uint32_t *)(v10 + 8));
    goto LABEL_10;
  }
  if ( v8[5] == v10 )
    goto LABEL_15;
LABEL_10:
  if ( *v7 && (v15 = *v7 - 1, v16 = *(uint32_t *)off_11DC1C, (*v7 = v15) == 0) && v16 )
  {
    __enable_irq();
    if ( (int)(v13 - *((uint32_t *)off_11DC28 + 4)) < 0 )
      return set_busy_flag_alt(0x10000000);
  }
  else if ( (int)(v13 - *((uint32_t *)off_11DC28 + 4)) < 0 )
  {
    return set_busy_flag_alt(0x10000000);
  }
  return result;
}

