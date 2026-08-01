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

extern uint32_t off_115DF0;
extern uint32_t dword_115DEC;
extern uint32_t dword_115DE8;
extern uint32_t dword_115DE4;
extern uint32_t off_115DF4;
extern uint32_t off_115E1C;
extern uint32_t off_115DF8;
extern uint32_t off_115E20;
extern uint32_t off_115DFC;
extern uint32_t off_115E00;
extern uint32_t off_115E24;
extern uint32_t off_115E04;
extern uint32_t off_115E08;
extern uint32_t off_115E18;
extern uint32_t off_115E0C;

// ll_init_tables @ 0x115c20, size 452 bytes
void __noreturn ll_init_tables()
{
  int *v0; // r5
  uint8_t **v1; // r10
  int v2; // r3
  int v3; // r0
  uint8_t *v4; // r7
  int *v5; // r8
  int *v6; // r4
  int *v7; // r6
  uint8_t *v8; // r11
  int v9; // r2
  int v10; // r3
  int v11; // r3
  int v12; // r2
  int v13; // r1
  int v14; // r3

  v0 = (int *)off_115DF0;
  alloc_tx_event(dword_115DEC, dword_115DE8, dword_115DE4);
  if ( *(uint32_t *)off_115DF4 )
  {
    write_mmio_register();
    if ( *(uint16_t *)(*v0 + 8) )
      rf_set_channel(*(uint16_t *)(*v0 + 8));
  }
  v1 = (uint8_t **)off_115E1C;
  if ( **(uint8_t **)off_115E1C == 2 )
  {
    v2 = *v0;
    *(uint8_t *)(v2 + 6) = 2;
    *(uint8_t *)(v2 + 3) = 1;
  }
  v3 = scheduler_entry(*(uint16_t *)(*v0 + 4));
  if ( !*(uint8_t *)(*v0 + 3) )
    sub_114588();
  __enable_irq();
  __dsb(0xFu);
  __isb(0xFu);
  v4 = off_115DF8;
  v5 = (int *)off_115E20;
  v6 = (int *)off_115DFC;
  v7 = (int *)off_115E00;
  v8 = off_115E24;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( *(uint8_t *)(*v0 + 3) )
        memory_barrier();
      if ( !*v4 )
        v3 = process_event_queue(v3);
      v3 = rf_calibration_proc(v3);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v5 = 1;
      }
      v9 = *v7;
      v10 = *v6 + 1;
      *v6 = v10;
      if ( !v9 )
        break;
      if ( v10 )
        goto LABEL_15;
    }
    v3 = sleep_mode_read(v3);
    if ( *(uint8_t *)(*v0 + 3) )
      sub_114588();
    if ( **v1 == 1 && *(uint8_t *)off_115E04 )
      break;
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
      v3 = fault_status_read(v3, v13);
    }
    while ( !v3 );
    if ( !*(uint8_t *)(*v0 + 3) )
      goto LABEL_23;
LABEL_28:
    set_state_flag();
    if ( v8[1] )
LABEL_29:
      v3 = rf_power_control();
LABEL_24:
    v10 = *v6;
    if ( *v6 )
    {
LABEL_15:
      v11 = v10 - 1;
      v12 = *v5;
      *v6 = v11;
      if ( !v11 )
      {
        if ( v12 )
          __enable_irq();
      }
    }
  }
  v14 = **(uint8_t **)off_115E08;
  if ( v14 == 3 )
  {
    v3 = get_init_flag();
    if ( v3 )
      goto LABEL_36;
    v14 = **(uint8_t **)off_115E08;
  }
  if ( v14 == 1 )
  {
    if ( !v8[1] || *(uint8_t *)off_115E18 )
      goto LABEL_21;
  }
  else if ( v14 || !*(uint8_t *)off_115E0C || !v8[1] )
  {
    goto LABEL_21;
  }
LABEL_36:
  mmio_read_bit13(v3);
  while ( 1 )
    ;
}

