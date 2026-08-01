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

extern uint32_t off_1357B0;

// rf_write_cal_param @ 0x135780, size 48 bytes
uint32_t * rf_write_cal_param(int16_t a1)
{
  int v2; // r5
  int v3; // r0

  v2 = *((uint32_t *)off_1357B0 + 4);
  v3 = bt_buf_alloc(30, 0, 6, 4u);
  *(uint16_t *)v3 = a1;
  *(uint8_t *)(v3 + 2) = 1;
  *(uint8_t *)(v3 + 3) = *(uint8_t *)(v2 + 61);
  hci_evt_send(v3);
  return hci_cmd_send(6u, 9);
}

