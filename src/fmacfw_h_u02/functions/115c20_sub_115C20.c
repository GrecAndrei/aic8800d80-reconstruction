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


extern uint32_t dword_115DF0;
extern uint32_t dword_115DF4;
extern uint32_t dword_115DF8;
extern uint32_t dword_115DFC;
extern uint32_t dword_115E00;
extern uint32_t dword_115E04;
extern uint32_t dword_115E08;
extern uint32_t dword_115E0C;
extern uint32_t dword_115E14;
extern uint32_t dword_115E18;
extern uint32_t dword_115E1C;
extern uint32_t dword_115E20;
extern uint32_t dword_115E24;

// ll_init_tables @ 0x115c20, size 452 bytes
void  ll_init_tables(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r5
  uint8_t **v5; // r10
  int v6; // r3
  int v7; // r0
  int v8; // r1
  uint8_t *v9; // r7
  int *v10; // r8
  int *v11; // r4
  int *v12; // r6
  unsigned int v13; // r11
  int v14; // r2
  int v15; // r3
  int v16; // r3
  int v17; // r2
  int v18; // r3
  volatile unsigned int v19; // r2
  unsigned int v20; // r2
  volatile unsigned int v21; // r3
  uint32_t *v22; // r2

  v4 = dword_115DF0;
  alloc_tx_event("\x9A%s - build: %s\n", aV6911, aLaJul032024152);
  if ( *(uint32_t *)dword_115DF4 )
  {
    write_mmio_register();
    if ( *(uint16_t *)(*(uint32_t *)v4 + 8) )
      rf_set_channel_1(*(uint16_t *)(*(uint32_t *)v4 + 8));
  }
  v5 = (uint8_t **)dword_115E1C;
  if ( **(uint8_t **)dword_115E1C == 2 )
  {
    v6 = *(uint32_t *)v4;
    *(uint8_t *)(v6 + 6) = 2;
    *(uint8_t *)(v6 + 3) = 1;
  }
  v7 = scheduler_entry(*(uint16_t *)(*(uint32_t *)v4 + 4));
  if ( !*(uint8_t *)(*(uint32_t *)v4 + 3) )
    rf_emit_setup_word();
  __enable_irq();
  __dsb(0xFu);
  __isb(0xFu);
  v9 = (uint8_t *)dword_115DF8;
  v10 = (int *)dword_115E20;
  v11 = (int *)dword_115DFC;
  v12 = (int *)dword_115E00;
  v13 = dword_115E24;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( *(uint8_t *)(*(uint32_t *)v4 + 3) )
        memory_barrier();
      if ( !*v9 )
        process_event_queue();
      v7 = rf_calibration_proc(v7, v8);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v10 = 1;
      }
      v14 = *v12;
      v15 = *v11 + 1;
      *v11 = v15;
      if ( !v14 )
        break;
      if ( v15 )
        goto LABEL_15;
    }
    sleep_mode_read(v7);
    if ( *(uint8_t *)(*(uint32_t *)v4 + 3) )
      rf_emit_setup_word();
    if ( **v5 == 1 && *(uint8_t *)dword_115E04 )
      break;
    do
    {
LABEL_21:
      __dsb(0xFu);
      __wfi();
      __isb(0xFu);
      if ( **v5 != 3 )
      {
        if ( *(uint8_t *)(*(uint32_t *)v4 + 3) )
          goto LABEL_28;
LABEL_23:
        if ( *(uint8_t *)(v13 + 1) )
          goto LABEL_29;
        goto LABEL_24;
      }
      v7 = fault_status_read();
    }
    while ( !v7 );
    if ( !*(uint8_t *)(*(uint32_t *)v4 + 3) )
      goto LABEL_23;
LABEL_28:
    set_state_flag();
    if ( *(uint8_t *)(v13 + 1) )
LABEL_29:
      v7 = rf_power_control();
LABEL_24:
    v15 = *v11;
    if ( *v11 )
    {
LABEL_15:
      v16 = v15 - 1;
      v17 = *v10;
      *v11 = v16;
      if ( !v16 )
      {
        if ( v17 )
          __enable_irq();
      }
    }
  }
  v18 = **(uint8_t **)dword_115E08;
  if ( v18 == 3 )
  {
    v7 = get_init_flag();
    if ( v7 )
      goto LABEL_36;
    v18 = **(uint8_t **)dword_115E08;
  }
  if ( v18 == 1 )
  {
    if ( !*(uint8_t *)(v13 + 1) || *(uint8_t *)dword_115E18 )
      goto LABEL_21;
  }
  else if ( v18 || !*(uint8_t *)dword_115E0C || !*(uint8_t *)(v13 + 1) )
  {
    goto LABEL_21;
  }
LABEL_36:
  mmio_read_bit13();
  v19 = (*(volatile uint32_t *)0x40501010u);
  v20 = v19 + 28;
  do
    v21 = (*(volatile uint32_t *)0x40501010u);
  while ( (int)(v20 - v21) >= 0 );
  v22 = (uint32_t *)dword_115E14;
  *(uint32_t *)(dword_115E14 + 4) |= 0x1000u;
  v22[21] |= 0x1000u;
  *v22 |= 0x1000u;
  goto LABEL_21;
}
