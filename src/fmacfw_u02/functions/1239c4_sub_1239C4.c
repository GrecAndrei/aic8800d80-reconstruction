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

extern uint32_t off_123A84;
extern uint32_t dword_123A88;
extern uint32_t off_123A8C;
extern uint32_t dword_123A90;

// ble_radio_cfg_write @ 0x1239c4, size 192 bytes
int  ble_radio_cfg_write(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  uint32_t *v5; // r5
  uint32_t *v6; // r3
  int v7; // r4
  BOOL v8; // r0
  int v9; // r3

  v4 = ke_msg_alloc(5, a4, a3, 28);
  v5 = off_123A84;
  *(uint32_t *)v4 = dword_123A88;
  v6 = off_123A8C;
  *(uint32_t *)(v4 + 4) = *v5;
  *(uint32_t *)(v4 + 8) = *v6;
  *(uint8_t *)(v4 + 26) = 4;
  *(uint16_t *)(v4 + 24) = 32;
  v7 = v4;
  rf_read_timestamps((uint32_t *)(v4 + 12), (uint32_t *)(v4 + 16));
  *(uint32_t *)(v7 + 20) = dword_123A90;
  if ( (*v5 & 0x20000) != 0 && rf_get_status_bit28() )
  {
    *(uint32_t *)(v7 + 20) |= 0x400u;
    if ( (*(uint32_t *)off_123A84 & 0x20000) == 0 )
      goto LABEL_3;
  }
  else if ( (*(uint32_t *)off_123A84 & 0x20000) == 0 )
  {
    goto LABEL_3;
  }
  if ( rf_get_status_bit30() )
    *(uint32_t *)(v7 + 20) |= 0x4000u;
LABEL_3:
  if ( (*(uint32_t *)off_123A84 & 0x2000) != 0 )
    *(uint32_t *)(v7 + 20) |= 0x1000u;
  if ( return_true() )
    *(uint32_t *)(v7 + 20) |= 0x200u;
  if ( (*(uint32_t *)off_123A84 & 0x8000) != 0 && rf_get_status_bit21() )
    *(uint32_t *)(v7 + 20) |= 0x800000u;
  v8 = rf_check_status();
  v9 = *(uint32_t *)(v7 + 20);
  if ( v8 )
    v9 |= 0x80000u;
  *(uint32_t *)(v7 + 20) = v9 | 0x600000;
  ke_msg_send(v7);
  return 0;
}

