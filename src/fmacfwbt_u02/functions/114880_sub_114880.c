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


extern uint32_t off_114904;

// semaphore_create @ 0x114880, size 132 bytes
int  semaphore_create(int a1, int *a2, uint16_t a3, uint16_t a4)
{
  uint8_t *v7; // r5
  int v8; // r9
  int v9; // r8
  int v10; // r0
  uint16_t *v11; // r3

  v7 = (uint8_t *)bt_buf_alloc(3089, a4, a3, 1);
  v8 = *a2;
  v9 = *((uint8_t *)a2 + 4);
  v10 = dispatch_by_cmd((uint8_t *)a2 + 4);
  if ( v10 < 0 )
  {
    ke_event_schedule_1("bt type err:%d, len=%d\n", v9, v8);
    hci_evt_send((int)v7);
    return 0;
  }
  else if ( v8 == v10 )
  {
    v11 = off_114904;
    *((uint16_t *)off_114904 + 12) = a3;
    v11[13] = a4;
    invoke_callback(a2);
    *v7 = 1;
    ke_event_schedule_1("\x9D\x81sdio_bt: [%d] len=%d\n", v9, v8);
    hci_evt_send((int)v7);
    return 1;
  }
  else
  {
    ke_event_schedule_1("bt len err:%d,%d\n", v10, v8);
    hci_evt_send((int)v7);
    return 0;
  }
}
