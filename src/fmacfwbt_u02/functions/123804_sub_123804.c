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

extern uint32_t dword_123890;
extern uint32_t off_123894;
extern uint32_t off_123898;

// rf_reg_write_53 @ 0x123804, size 140 bytes
// Doc: sub_1223804 [ipc]: SDIO/host cmd prep issuing 0x53/0xd to helper
// sub_1223804 [ipc]: SDIO/host cmd prep issuing 0x53/0xd to helper
int  rf_reg_write_53(int a1, uint8_t *a2)
{
  uint8_t *v3; // r0
  uint8_t *v4; // r4
  unsigned int v5; // r0
  int v6; // r0

  v3 = (uint8_t *)bt_buf_alloc(83, 13, 0, 1);
  *v3 = 1;
  v4 = v3;
  v5 = *a2;
  if ( v5 > 4 )
    goto LABEL_6;
  v6 = dword_123890 + 1320 * v5;
  if ( !*(uint8_t *)(v6 + 1224) )
    goto LABEL_6;
  if ( a2[2] )
  {
    if ( bt_conn_state_machine(
           v6,
           0,
           a2[3],
           a2[2],
           *((uint32_t *)a2 + 2),
           *((uint32_t *)a2 + 1),
           (*(uint16_t *)(v6 + 222) << 10)
         + *(uint32_t *)off_123894 / (*(uint16_t *)(v6 + 222) << 10) * (*(uint16_t *)(v6 + 222) << 10)
         + *((uint32_t *)off_123898 + 4)
         - *(uint32_t *)off_123894
         + *((uint32_t *)a2 + 3)) != 255 )
      *v4 = 0;
LABEL_6:
    hci_evt_send(v4);
    return 0;
  }
  *v4 = bt_conn_get_state();
  hci_evt_send(v4);
  return 0;
}

