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


extern uint32_t off_112BFC;
extern uint32_t off_112C00;
extern uint32_t off_112C08;
extern uint32_t off_112C0C;
extern uint32_t off_112C10;
extern uint32_t off_112C14;

// wait_rf_ready_1 @ 0x112b7c, size 126 bytes
int  wait_rf_ready_1(int a1)
{
  uint16_t *v2; // r4
  int v3; // r2
  int v4; // r1
  uint8_t *v5; // r1
  uint8_t *v6; // r2
  int v7; // r7
  int v8; // r1
  int v9; // r4

  if ( (*(uint32_t *)off_112BFC & 0x2000000) != 0 )
  {
    memset_thunk((int *)off_112C00, 0xFFu, 4u);
  }
  else
  {
    v2 = (uint16_t *)off_112C00;
    memset_thunk((int *)off_112C00, 0xFFu, 4u);
    if ( mmio_write_400000_4((int)v2) || (v3 = v2[1], v3 == 0xFFFF) || (v4 = *v2, v4 == 0xFFFF) )
      dispatch_event_handler_1(aNoUsbInfoInFla);
    else
      dispatch_event_handler_1("get vid %x, pid %x\r\n", v4, v3);
  }
  v5 = off_112C0C;
  v6 = off_112C10;
  *(uint32_t *)off_112C08 = *(uint32_t *)a1;
  v7 = off_112C14;
  *v5 = 0;
  *v6 = 0;
  do
  {
    v8 = *(uint8_t *)(a1 + 8);
    if ( *(uint8_t *)(a1 + 8) )
      v8 = 1;
    v9 = ke_send_event(v7, v8);
    dispatch_event_handler_1("open res:%d\n", v9);
  }
  while ( v9 );
  return 0;
}
