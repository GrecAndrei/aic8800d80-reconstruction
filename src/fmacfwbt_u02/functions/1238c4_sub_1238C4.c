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

// call_127d80_remapped @ 0x1238c4, size 54 bytes
// Doc: sub_12238C4 [unknown]: Bridge helper forwarding args to 0x127d80
// sub_12238C4 [unknown]: Bridge helper forwarding args to 0x127d80
int  call_127d80_remapped(int a1, uint8_t *a2, int a3, int a4)
{
  char v7; // r0
  char v9; // r6
  uint8_t *v10; // r0

  v7 = rx_packet_handler(a2, a4);
  if ( a4 )
  {
    v9 = v7;
    v10 = (uint8_t *)bt_buf_alloc(71, a4, a3, 3);
    *v10 = *a2;
    v10[1] = v9;
    v10[2] = 4;
    hci_evt_send(v10);
  }
  return 0;
}

