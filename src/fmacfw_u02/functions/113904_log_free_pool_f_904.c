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

extern uint32_t off_1139A4;
extern uint32_t off_1139B0;
extern uint32_t off_1139B8;
extern uint32_t dword_1139C0;

// assert_fault @ 0x113904, size 156 bytes
// Doc: rf_msg_handler_0x2f0 [ipc]: RF message body handler for message id 0x2f0
// rf_msg_handler_0x2f0 [ipc]: RF message body handler for message id 0x2f0
void assert_fault()
{
  int *v0; // r4
  int v1; // r0
  uint8_t *v2; // r1
  int v3; // r0
  uint16_t v4; // r3
  int v5; // r3
  int v6; // r2
  int v7; // r3

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)rf_cmd_queue_next_n4ec = 1;
  }
  v0 = (int *)off_1139A4;
  v1 = rf_cmd_queue_next_n4f4;
  ++*(uint32_t *)off_1139A4;
  cmd_handler_a(v1);
  v2 = off_1139B0;
  v3 = *(uint8_t *)off_1139B0;
  v4 = *(uint16_t *)rf_cmd_queue_next + 1;
  *(uint16_t *)rf_cmd_queue_next = v4;
  if ( v3 && *(uint8_t *)rf_bus_write2_n_2ca <= (unsigned int)v4 )
  {
    v7 = *(uint8_t *)off_1139B8;
    *v2 = 0;
    if ( v7 )
      *((uint32_t *)rf_msg_process_body_n_28c + 512) &= ~0x2000u;
    else
      *((uint32_t *)rf_msg_process_body_n_28c + 713) &= ~1u;
    state_check_4_b(1);
    ke_int_lock(1069, 1);
    check_status_bits(512, dword_1139C0);
    if ( !*(uint8_t *)rf_cmd_process_n46c )
      read_state_flag();
  }
  if ( *v0 )
  {
    v5 = *v0 - 1;
    v6 = *(uint32_t *)rf_cmd_queue_next_n4ec;
    *v0 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
}

