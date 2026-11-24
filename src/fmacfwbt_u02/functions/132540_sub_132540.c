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

// sdio_cfg_write @ 0x132540, size 20 bytes
int  sdio_cfg_write(int a1)
{
  uint8_t *v2; // r4

  v2 = (uint8_t *)bt_buf_alloc(12, 0, 5, 1);
  rf_calibrate_1(a1);
  *v2 = a1;
  hci_evt_send((int)v2);
  return hci_evt_alloc_send(5130, 13, 5);
}
