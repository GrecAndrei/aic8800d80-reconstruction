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


extern uint32_t off_122F50;
extern uint32_t off_122F54;

// is_valid_conn_handle @ 0x122f10, size 64 bytes
int  is_valid_conn_handle(int a1, char *a2, int a3, int a4)
{
  int v4; // r0
  int v8; // r1
  uint8_t *v9; // r2
  BOOL v10; // r0

  v4 = (uint8_t)a2[1];
  if ( v4 != 255 )
    rf_scan_start(v4);
  v8 = (uint8_t)*a2;
  v9 = off_122F54;
  if ( *a2 )
    v8 = 1;
  v10 = a2[2] != 0;
  *(uint8_t *)off_122F50 = v10;
  *v9 = v8;
  ke_event_schedule_1("set agg disable=%d, disable_rx=%d\n", v8, v10);
  hci_evt_alloc_send(100, a4, a3);
  return 0;
}
