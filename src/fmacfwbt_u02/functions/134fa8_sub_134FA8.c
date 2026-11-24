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


extern uint32_t dword_135004;
extern uint32_t off_135000;

// init_rf_config @ 0x134fa8, size 86 bytes
int  init_rf_config(int a1, int a2, int a3)
{
  uint32_t *v3; // r5

  v3 = off_135000;
  *((uint8_t *)off_135000 + 4) = a3;
  v3[2] = a1;
  *((uint16_t *)v3 + 6) = a2;
  hci_cmd_send(6u, 10);
  state_check_feature(
    256,
    "disconnct:%d,%d, sta_tx_cnt=%d, host_init=%d\r\n",
    *(uint8_t *)(a1 + 107),
    a2,
    *(uint16_t *)(dword_135004 + 696 * *(uint8_t *)(a1 + 116) + 50),
    a3);
  if ( *((uint8_t *)v3 + 4) )
    return rx_desc_read_status();
  else
    return mac_tx_start();
}
