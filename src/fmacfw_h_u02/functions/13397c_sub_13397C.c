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

extern uint32_t off_133A88;
extern uint32_t dword_133AA0;
extern uint32_t dword_133A9C;
extern uint32_t off_133A8C;
extern uint32_t off_133A90;
extern uint32_t dword_133A94;
extern uint32_t dword_133A98;

// ble_state_check_13397c @ 0x13397c, size 266 bytes
int ble_state_check_13397c()
{
  int v0; // r2
  unsigned int v1; // r3
  uint8_t *v2; // r3
  uint8_t *v4; // r4
  int v5; // r3
  int v6; // r1
  int v7; // [sp+0h] [bp-Ch] BYREF
  int v8; // [sp+4h] [bp-8h] BYREF

  if ( **(int16_t **)off_133A88 < 0 && hci_cmd_handler(6u) != 4 && hci_cmd_handler(6u) != 10 )
    irq_disable_mmio_write(dword_133AA0, dword_133A9C, 697);
  if ( hci_cmd_handler(6u) == 10 )
  {
    v4 = off_133A8C;
    v5 = *((uint8_t *)off_133A8C + 4);
    *(uint32_t *)(*((uint32_t *)off_133A8C + 2) + 472) = 0;
    if ( v5 )
    {
      mac_write_header_word(6148, 13, 6);
      v4[4] = 0;
    }
    rx_process_packet(*(uint32_t *)v4 + 12);
    v6 = (uint8_t)v4[33];
    *(uint32_t *)v4 = 0;
    if ( v6 )
    {
      v7 = 0;
      v8 = 0;
      ble_get_addr_flag(&v7, &v8);
      ble_parse_event(v7, v8, 0);
    }
    else
    {
      hci_cmd_preprocess(6u, 0);
    }
    return 0;
  }
  else
  {
    v0 = *((uint32_t *)off_133A8C + 4);
    v1 = *(uint8_t *)(v0 + 59);
    if ( v1 == 2 )
    {
      if ( (*(uint32_t *)(v0 + 48) & 0x40) != 0 )
      {
        mac_dma_setup();
        v2 = off_133A90;
        if ( *((uint8_t *)off_133A90 + 13) )
        {
LABEL_6:
          if ( (v2[15] & 1) != 0 )
          {
            ke_event_handler(6155, 6, dword_133A94);
            enable_clock_2();
          }
        }
        return 0;
      }
LABEL_5:
      ll_evt_schedule(1, 0);
      v2 = off_133A90;
      if ( *((uint8_t *)off_133A90 + 13) )
        goto LABEL_6;
      return 0;
    }
    if ( v1 <= 2 )
      goto LABEL_5;
    if ( v1 == 3 )
    {
      rf_chan_state_get(dword_133A98);
      if ( *((uint8_t *)off_133A90 + 13) )
        *((uint8_t *)off_133A90 + 15) |= 2u;
      return 0;
    }
    assert_trace(1);
    return 0;
  }
}

