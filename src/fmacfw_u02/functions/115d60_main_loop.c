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

extern uint32_t off_115F30;
extern uint32_t dword_115F2C;
extern uint32_t dword_115F28;
extern uint32_t dword_115F24;
extern uint32_t off_115F34;
extern uint32_t off_115F5C;
extern uint32_t off_115F38;
extern uint32_t off_115F60;
extern uint32_t off_115F3C;
extern uint32_t off_115F40;
extern uint32_t off_115F64;
extern uint32_t off_115F44;
extern uint32_t off_115F48;
extern uint32_t off_115F58;
extern uint32_t off_115F4C;

// copy_global_data @ 0x115d60, size 452 bytes
// Doc: ipc_doorbell_init_handlers [ipc]: Initialize IPC doorbell handler table and route callbacks
// ipc_doorbell_init_handlers [ipc]: Initialize IPC doorbell handler table and route callbacks
void __noreturn copy_global_data()
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

  v0 = (int *)off_115F30;
  event_dispatch(dword_115F2C, dword_115F28, dword_115F24);
  if ( *(uint32_t *)off_115F34 )
  {
    mmio_write_70001408();
    if ( *(uint16_t *)(*v0 + 8) )
      rf_set_frequency(*(uint16_t *)(*v0 + 8));
  }
  v1 = (uint8_t **)off_115F5C;
  if ( **(uint8_t **)off_115F5C == 2 )
  {
    v2 = *v0;
    *(uint8_t *)(v2 + 6) = 2;
    *(uint8_t *)(v2 + 3) = 1;
  }
  v3 = load_global_ptr_182558(*(uint16_t *)(*v0 + 4));
  if ( !*(uint8_t *)(*v0 + 3) )
    clear_global_flag_2();
  __enable_irq();
  __dsb(0xFu);
  __isb(0xFu);
  v4 = off_115F38;
  v5 = (int *)off_115F60;
  v6 = (int *)off_115F3C;
  v7 = (int *)off_115F40;
  v8 = off_115F64;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( *(uint8_t *)(*v0 + 3) )
        dummy_store_global();
      if ( !*v4 )
        v3 = tx_ring_peek(v3);
      v3 = parse_large_ioctl(v3);
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
        goto ipc_doorbell_handler_n470;
    }
    v3 = clear_rx_config(v3);
    if ( *(uint8_t *)(*v0 + 3) )
      clear_global_flag_2();
    if ( **v1 == 1 && *(uint8_t *)off_115F44 )
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
          goto ipc_doorbell_handler_n4f2;
        goto LABEL_24;
      }
      v3 = check_nvic_irq_status(v3, v13);
    }
    while ( !v3 );
    if ( !*(uint8_t *)(*v0 + 3) )
      goto LABEL_23;
LABEL_28:
    set_global_flag_2();
    if ( v8[1] )
ipc_doorbell_handler_n4f2:
      v3 = peripheral_clock_enable();
LABEL_24:
    v10 = *v6;
    if ( *v6 )
    {
ipc_doorbell_handler_n470:
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
  v14 = **(uint8_t **)off_115F48;
  if ( v14 == 3 )
  {
    v3 = get_status_flag();
    if ( v3 )
      goto LABEL_36;
    v14 = **(uint8_t **)off_115F48;
  }
  if ( v14 == 1 )
  {
    if ( !v8[1] || *(uint8_t *)off_115F58 )
      goto LABEL_21;
  }
  else if ( v14 || !*(uint8_t *)off_115F4C || !v8[1] )
  {
    goto LABEL_21;
  }
LABEL_36:
  ipc_wait_flag(v3);
  while ( 1 )
    ;
}

