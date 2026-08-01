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

extern uint32_t off_11636C;
extern uint32_t dword_116368;
extern uint32_t dword_116364;
extern uint32_t dword_116360;
extern uint32_t off_116370;
extern uint32_t off_11639C;
extern uint32_t off_116374;
extern uint32_t off_1163A0;
extern uint32_t off_116378;
extern uint32_t off_11637C;
extern uint32_t off_1163A4;
extern uint32_t off_116380;
extern uint32_t off_11638C;
extern uint32_t off_116384;
extern uint32_t off_116388;
extern uint32_t off_116398;

// ke_init_structures @ 0x116188, size 472 bytes
// Doc: sub_1216188 [patch]: Initialization routine loading multiple config pointers and calling setup
// sub_1216188 [patch]: Initialization routine loading multiple config pointers and calling setup
void __noreturn ke_init_structures()
{
  int *v0; // r5
  uint8_t **v1; // r8
  int v2; // r3
  int v3; // r0
  uint8_t *v4; // r7
  int *v5; // r9
  int *v6; // r4
  int *v7; // r6
  uint8_t *v8; // r11
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r3
  int v13; // r2
  int v14; // r3

  v0 = (int *)off_11636C;
  ke_event_schedule(dword_116368, dword_116364, dword_116360);
  if ( *(uint32_t *)off_116370 )
  {
    write_reg_70001408();
    if ( *(uint16_t *)(*v0 + 8) )
      periph_field_set(*(uint16_t *)(*v0 + 8));
  }
  v1 = (uint8_t **)off_11639C;
  if ( **(uint8_t **)off_11639C == 2 )
  {
    v2 = *v0;
    *(uint8_t *)(v2 + 6) = 2;
    *(uint8_t *)(v2 + 3) = 1;
  }
  v3 = init_chip_state(*(uint16_t *)(*v0 + 4));
  if ( !*(uint8_t *)(*v0 + 3) )
    clear_hw_flag_bit();
  __enable_irq();
  __dsb(0xFu);
  __isb(0xFu);
  v4 = off_116374;
  v5 = (int *)off_1163A0;
  v6 = (int *)off_116378;
  v7 = (int *)off_11637C;
  v8 = off_1163A4;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( *(uint8_t *)(*v0 + 3) )
        hw_sync_write();
      if ( !*v4 )
        v3 = process_event_queue(v3);
      v3 = ke_event_send(v3);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v5 = 1;
      }
      v10 = *v7;
      v11 = *v6 + 1;
      *v6 = v11;
      if ( !v10 )
        break;
      if ( v11 )
        goto LABEL_15;
    }
    if ( *((uint8_t *)off_116380 + 18) )
    {
      *(uint8_t *)off_11638C = 0;
      if ( *(uint8_t *)(*v0 + 3) )
LABEL_39:
        clear_hw_flag_bit();
    }
    else
    {
      rx_check_buffers();
      if ( *(uint8_t *)(*v0 + 3) )
        goto LABEL_39;
    }
    if ( **v1 == 1 && *(uint8_t *)off_116384 )
    {
      v14 = **(uint8_t **)off_116388;
      if ( v14 == 3 )
      {
        v3 = ll_util_get_state();
        if ( !v3 )
        {
          v14 = **(uint8_t **)off_116388;
          goto LABEL_32;
        }
      }
      else
      {
LABEL_32:
        if ( v14 == 1 )
        {
          if ( !v8[1] || *(uint8_t *)off_116398 )
            goto LABEL_21;
        }
        else if ( v14 || !*(uint8_t *)off_11638C || !v8[1] )
        {
          goto LABEL_21;
        }
      }
      hw_poll_flag(v3);
      while ( 1 )
        ;
    }
    do
    {
LABEL_21:
      __dsb(0xFu);
      __wfi();
      __isb(0xFu);
      if ( **v1 != 3 )
      {
        if ( *(uint8_t *)(*v0 + 3) )
          goto LABEL_28;
LABEL_23:
        if ( v8[1] )
          goto LABEL_29;
        goto LABEL_24;
      }
      v3 = check_nvic_irq(v3, v9);
    }
    while ( !v3 );
    if ( !*(uint8_t *)(*v0 + 3) )
      goto LABEL_23;
LABEL_28:
    set_hw_flag_bit();
    if ( v8[1] )
LABEL_29:
      v3 = rf_clock_enable();
LABEL_24:
    v11 = *v6;
    if ( *v6 )
    {
LABEL_15:
      v12 = v11 - 1;
      v13 = *v5;
      *v6 = v12;
      if ( !v12 )
      {
        if ( v13 )
          __enable_irq();
      }
    }
  }
}

