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

extern uint32_t dword_123800;

// rf_reg_write_54 @ 0x1237b0, size 80 bytes
int  rf_reg_write_54(int a1, uint8_t *a2)
{
  uint8_t *v3; // r0
  uint8_t *v4; // r4
  unsigned int v5; // r0

  v3 = (uint8_t *)bt_buf_alloc(84, 13, 0, 1);
  *v3 = 1;
  v4 = v3;
  v5 = *a2;
  if ( v5 > 4 || !*(uint8_t *)(dword_123800 + 1320 * v5 + 1224) )
    goto LABEL_5;
  *v4 = 0;
  if ( a2[1] )
  {
    bt_conn_set_flag();
LABEL_5:
    hci_evt_send(v4);
    return 0;
  }
  bt_conn_get_flag();
  hci_evt_send(v4);
  return 0;
}

