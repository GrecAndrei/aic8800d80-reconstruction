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

extern uint32_t off_122F54;
extern uint32_t off_122F50;
extern uint32_t dword_122F58;

// is_valid_conn_handle @ 0x122f10, size 64 bytes
int  is_valid_conn_handle(int a1, uint8_t *a2, int a3, int a4)
{
  int v7; // r1
  uint8_t *v8; // r2
  BOOL v9; // r0
  int v10; // r3

  if ( a2[1] != 255 )
    rf_scan_start();
  v7 = *a2;
  v8 = off_122F54;
  if ( *a2 )
    v7 = 1;
  v9 = a2[2] != 0;
  *(uint8_t *)off_122F50 = v9;
  *v8 = v7;
  ke_event_schedule(dword_122F58, v7, v9);
  hci_evt_alloc_send(100, a4, a3, v10);
  return 0;
}

