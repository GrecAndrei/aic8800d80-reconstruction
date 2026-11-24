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


extern uint32_t dword_11636C;
extern uint32_t dword_116370;
extern uint32_t dword_116374;
extern uint32_t dword_116378;
extern uint32_t dword_11637C;
extern uint32_t dword_116380;
extern uint32_t dword_116384;
extern uint32_t dword_116388;
extern uint32_t dword_11638C;
extern uint32_t dword_116394;
extern uint32_t dword_116398;
extern uint32_t dword_11639C;
extern uint32_t dword_1163A0;
extern uint32_t dword_1163A4;

// ke_init_structures @ 0x116188, size 472 bytes
void  ke_init_structures()
{
  unsigned int v0; // r5
  uint8_t **v1; // r8
  int v2; // r3
  int v3; // r0
  int v4; // r1
  uint8_t *v5; // r7
  int *v6; // r9
  int *v7; // r4
  int *v8; // r6
  unsigned int v9; // r11
  int v10; // r2
  int v11; // r3
  int v12; // r3
  int v13; // r2
  int v14; // r3
  volatile unsigned int v15; // r2
  unsigned int v16; // r2
  volatile unsigned int v17; // r3
  uint32_t *v18; // r2

  v0 = dword_11636C;
  ke_event_schedule_1("\x9A%s - build: %s\n", aV6911, aLaJul032024152);
  if ( *(uint32_t *)dword_116370 )
  {
    write_reg_70001408();
    if ( *(uint16_t *)(*(uint32_t *)v0 + 8) )
      periph_field_set(*(uint16_t *)(*(uint32_t *)v0 + 8));
  }
  v1 = (uint8_t **)dword_11639C;
  if ( **(uint8_t **)dword_11639C == 2 )
  {
    v2 = *(uint32_t *)v0;
    *(uint8_t *)(v2 + 6) = 2;
    *(uint8_t *)(v2 + 3) = 1;
  }
  v3 = init_chip_state(*(uint16_t *)(*(uint32_t *)v0 + 4));
  if ( !*(uint8_t *)(*(uint32_t *)v0 + 3) )
    clear_hw_flag_bit();
  __enable_irq();
  __dsb(0xFu);
  __isb(0xFu);
  v5 = (uint8_t *)dword_116374;
  v6 = (int *)dword_1163A0;
  v7 = (int *)dword_116378;
  v8 = (int *)dword_11637C;
  v9 = dword_1163A4;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( *(uint8_t *)(*(uint32_t *)v0 + 3) )
        hw_sync_write();
      if ( !*v5 )
        process_event_queue();
      v3 = ke_event_send_1(v3, v4);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v6 = 1;
      }
      v10 = *v8;
      v11 = *v7 + 1;
      *v7 = v11;
      if ( !v10 )
        break;
      if ( v11 )
        goto LABEL_15;
    }
    if ( *(uint8_t *)(dword_116380 + 0x12) )
    {
      *(uint8_t *)dword_11638C = 0;
      if ( *(uint8_t *)(*(uint32_t *)v0 + 3) )
LABEL_40:
        clear_hw_flag_bit();
    }
    else
    {
      rx_check_buffers(v3);
      if ( *(uint8_t *)(*(uint32_t *)v0 + 3) )
        goto LABEL_40;
    }
    if ( **v1 == 1 && *(uint8_t *)dword_116384 )
    {
      v14 = **(uint8_t **)dword_116388;
      if ( v14 == 3 )
      {
        v3 = ll_util_get_state();
        if ( !v3 )
        {
          v14 = **(uint8_t **)dword_116388;
          goto LABEL_32;
        }
      }
      else
      {
LABEL_32:
        if ( v14 == 1 )
        {
          if ( !*(uint8_t *)(v9 + 1) || *(uint8_t *)dword_116398 )
            goto LABEL_21;
        }
        else if ( v14 || !*(uint8_t *)dword_11638C || !*(uint8_t *)(v9 + 1) )
        {
          goto LABEL_21;
        }
      }
      hw_poll_flag();
      v15 = (*(volatile uint32_t *)0x40501010u);
      v16 = v15 + 28;
      do
        v17 = (*(volatile uint32_t *)0x40501010u);
      while ( (int)(v16 - v17) >= 0 );
      v18 = (uint32_t *)dword_116394;
      *(uint32_t *)(dword_116394 + 4) |= 0x1000u;
      v18[21] |= 0x1000u;
      *v18 |= 0x1000u;
      goto LABEL_21;
    }
    do
    {
LABEL_21:
      __dsb(0xFu);
      __wfi();
      __isb(0xFu);
      if ( **v1 != 3 )
      {
        if ( *(uint8_t *)(*(uint32_t *)v0 + 3) )
          goto LABEL_28;
LABEL_23:
        if ( *(uint8_t *)(v9 + 1) )
          goto LABEL_29;
        goto LABEL_24;
      }
      v3 = check_nvic_irq();
    }
    while ( !v3 );
    if ( !*(uint8_t *)(*(uint32_t *)v0 + 3) )
      goto LABEL_23;
LABEL_28:
    set_hw_flag_bit();
    if ( *(uint8_t *)(v9 + 1) )
LABEL_29:
      v3 = rf_clock_enable();
LABEL_24:
    v11 = *v7;
    if ( *v7 )
    {
LABEL_15:
      v12 = v11 - 1;
      v13 = *v6;
      *v7 = v12;
      if ( !v12 )
      {
        if ( v13 )
          __enable_irq();
      }
    }
  }
}
