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


extern uint32_t dword_113A24;
extern uint32_t dword_113A2C;
extern uint32_t dword_113A3C;
extern uint32_t off_113A0C;
extern uint32_t off_113A10;
extern uint32_t off_113A14;

// get_device_state @ 0x11394c, size 190 bytes
void  get_device_state()
{
  unsigned int v0; // r5
  int v1; // r4
  int v2; // lr
  unsigned int CPSR; // r1
  unsigned int v4; // r2
  unsigned int v5; // r5
  unsigned int v6; // r4
  unsigned int v7; // r4
  unsigned int v8; // r5
  int v9; // r1

  v0 = off_113A0C;
  v1 = *(uint32_t *)(*(uint32_t *)off_113A0C + 16);
  dispatch_event_handler_1("\nINT:%x,%x,%x", v1, *(uint32_t *)off_113A14, *(uint32_t *)off_113A10);
  if ( (v1 & 1) != 0 )
    *(uint32_t *)(*(uint32_t *)v0 + 12) = 1;
  CPSR = __get_CPSR();
  v4 = __get_CPSR();
  v5 = __get_CPSR();
  v6 = __get_CPSR();
  dispatch_event_handler_1(aControl08xXpsr_0, CPSR, v4, v5, v6, __get_CPSR(), v2);
  if ( v5 )
  {
    dispatch_event_handler_1(aWrongPsp);
    if ( !v6 )
      goto LABEL_5;
  }
  else if ( !v6 )
  {
    goto LABEL_5;
  }
  v7 = v6 & 0xFFFFFFF0;
  v8 = (dword_113A3C - v7) >> 2;
  dispatch_event_handler_1(aDumpmsp_0);
  v9 = v8;
  if ( v8 >= 0x100 )
    v9 = 256;
  handle_ipc_request(v7, v9, 4, 0);
LABEL_5:
  dispatch_event_handler_1(aIser);
  handle_ipc_request(dword_113A24, 8, 4, 0);
  dispatch_event_handler_1(aIspr);
  handle_ipc_request(dword_113A2C, 8, 4, 0);
  dispatch_event_handler_1(aTim2);
  handle_ipc_request((int)REG_4050_1000, 16, 4, 0);
  bt_check_state();
}
