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

extern uint32_t off_113A0C;
extern uint32_t dword_113A18;
extern uint32_t dword_113A1C;
extern uint32_t dword_113A38;
extern uint32_t dword_113A3C;
extern uint32_t dword_113A40;
extern uint32_t dword_113A20;
extern uint32_t dword_113A24;
extern uint32_t dword_113A28;
extern uint32_t dword_113A2C;
extern uint32_t dword_113A30;
extern uint32_t dword_113A34;

// get_device_state @ 0x11394c, size 190 bytes
void __noreturn get_device_state()
{
  void *v0; // r5
  int v1; // r4
  unsigned int CPSR; // r1
  unsigned int v3; // r5
  unsigned int v4; // r4
  int v5; // r1
  int v6; // r1
  int v7; // r1
  int f594; // r0
  unsigned int v9; // r4
  unsigned int v10; // r5
  int v11; // r1

  v0 = off_113A0C;
  v1 = *(uint32_t *)(*(uint32_t *)off_113A0C + 16);
  dispatch_event_handler(dword_113A18, v1);
  if ( (v1 & 1) != 0 )
    *(uint32_t *)(*(uint32_t *)v0 + 12) = 1;
  CPSR = __get_CPSR();
  __get_CPSR();
  v3 = __get_CPSR();
  v4 = __get_CPSR();
  __get_CPSR();
  dispatch_event_handler(dword_113A1C, CPSR);
  if ( v3 )
  {
    dispatch_event_handler(dword_113A38, v5);
    if ( !v4 )
      goto LABEL_5;
  }
  else if ( !v4 )
  {
    goto LABEL_5;
  }
  v9 = v4 & 0xFFFFFFF0;
  v10 = (dword_113A3C - v9) >> 2;
  dispatch_event_handler(dword_113A40, v5);
  v11 = v10;
  if ( v10 >= 0x100 )
    v11 = 256;
  handle_ipc_request(v9, v11, 4, 0);
LABEL_5:
  dispatch_event_handler(dword_113A20, v5);
  handle_ipc_request(dword_113A24, 8, 4, 0);
  dispatch_event_handler(dword_113A28, v6);
  handle_ipc_request(dword_113A2C, 8, 4, 0);
  dispatch_event_handler(dword_113A30, v7);
  f594 = handle_ipc_request(dword_113A34, 16, 4, 0);
  bt_check_state(f594);
}

