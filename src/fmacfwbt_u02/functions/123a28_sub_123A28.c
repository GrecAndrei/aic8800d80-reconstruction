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

extern uint32_t off_123AE0;
extern uint32_t dword_123AF0;
extern uint32_t dword_123AE8;
extern uint32_t dword_123AEC;
extern uint32_t off_123AE4;

// process_percent_char @ 0x123a28, size 184 bytes
// Doc: rf_get_cal_status [ipc]: Send IPC message with opcode 0x25 to peer core
// rf_get_cal_status [ipc]: Send IPC message with opcode 0x25 to peer core
int  process_percent_char(int a1, uint8_t *a2, int a3, int a4)
{
  uint8_t *v5; // r0
  int16_t **v6; // r6
  uint8_t *v7; // r5
  int v8; // r3

  v5 = (uint8_t *)bt_buf_alloc(37, a4, a3, 2);
  v6 = (int16_t **)off_123AE0;
  *v5 = 1;
  v7 = v5;
  if ( **v6 < 0 )
  {
    if ( *a2 <= 5u || (mmio_irq_clear(dword_123AF0, dword_123AE8, 1725), **v6 < 0) )
    {
      if ( a2[4] > 0x20u )
        mmio_irq_clear(dword_123AEC, dword_123AE8, 1726);
    }
  }
  switch ( a2[40] )
  {
    case 0u:
    case 1u:
    case 3u:
      v8 = (*(uint32_t *)off_123AE4 >> 6) & 1;
      goto LABEL_4;
    case 2u:
    case 5u:
    case 8u:
      v8 = (*(uint32_t *)off_123AE4 >> 7) & 1;
      goto LABEL_4;
    case 4u:
      v8 = (*(uint32_t *)off_123AE4 >> 13) & 1;
      goto LABEL_4;
    case 6u:
    case 7u:
      v8 = (*(uint32_t *)off_123AE4 >> 9) & 1;
LABEL_4:
      if ( v8 && a2[4] <= 0x20u && *a2 <= 5u )
      {
        v7[1] = rx_handle_frame(a2);
        *v7 = 0;
      }
      break;
    default:
      break;
  }
  hci_evt_send(v7);
  return 0;
}

