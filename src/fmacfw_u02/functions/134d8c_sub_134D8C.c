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

extern uint32_t off_134DE4;
extern uint32_t dword_134DEC;
extern uint32_t dword_134DE8;

// bt_schedule_ack_timeout @ 0x134d8c, size 86 bytes
int  bt_schedule_ack_timeout(int a1, int a2, int a3)
{
  uint32_t *v3; // r5

  v3 = off_134DE4;
  *((uint8_t *)off_134DE4 + 4) = a3;
  v3[2] = a1;
  *((uint16_t *)v3 + 6) = a2;
  rx_phy_status_parse(6u, 10);
  check_status_bits(
    256,
    dword_134DEC,
    *(uint8_t *)(a1 + 107),
    a2,
    *(uint16_t *)(dword_134DE8 + 696 * *(uint8_t *)(a1 + 116) + 50),
    a3);
  if ( *((uint8_t *)v3 + 4) )
    return bt_get_conn_state();
  else
    return bt_init_hci_buffer();
}

