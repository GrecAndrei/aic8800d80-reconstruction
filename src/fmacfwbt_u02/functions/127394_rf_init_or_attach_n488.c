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

extern uint32_t off_1274A8;
extern uint32_t off_1274A0;
extern uint32_t dword_1274A4;
extern uint32_t dword_1274BC;
extern uint32_t dword_1274C0;
extern uint32_t dword_1274AC;
extern uint32_t off_1274B0;
extern uint32_t dword_1274B8;
extern uint32_t dword_1274B4;

// rf_tx_packet @ 0x127394, size 266 bytes
// Doc: rf_tx_packet [rf]: Initialize/attach RF subsystem reading MMIO regs at 0x40501000 and table 0x190c30
// rf_tx_packet [rf]: Initialize/attach RF subsystem reading MMIO regs at 0x40501000 and table 0x190c30
int  rf_tx_packet(int result)
{
  uint8_t *v1; // r5
  uint64_t v2; // r6
  int v3; // r4
  char v4; // r3
  int v5; // r4
  int v6; // r9
  int v7; // r10
  int v8; // r7
  int v9; // r3
  int v10; // r11
  int v11; // r1
  int v12; // r0

  v1 = off_1274A8;
  LODWORD(v2) = result;
  HIDWORD(v2) = *((uint32_t *)off_1274A0 + 4) + *(uint32_t *)(result + 20);
  if ( result != dword_1274A4 || (*((uint8_t *)off_1274A8 + 88) & 4) != 0 )
  {
    if ( *((uint32_t *)off_1274A8 + 10) != result )
    {
      result = return_1000();
      HIDWORD(v2) += 4000 + result;
    }
    v3 = (uint8_t)v1[91];
    v4 = v1[88];
    *((uint64_t *)v1 + 10) = v2;
    if ( v3 )
    {
      v1[88] = v4 | 0x40;
    }
    else
    {
      v1[88] = v4 & 0xBF;
      hci_acl_buf_alloc();
      result = send_event_to_host(SHIDWORD(v2), 0, 0);
      v5 = *((uint32_t *)v1 + 4);
      if ( v5 )
      {
        v6 = dword_1274BC;
        v7 = dword_1274C0;
        v8 = dword_1274AC - HIDWORD(v2);
        while ( 1 )
        {
          v10 = *(uint32_t *)(v5 + 4);
          result = v10 - return_1000();
          if ( result + v8 >= 0 )
            break;
          v11 = *(uint32_t *)(v5 + 4);
          v12 = v6 + 1320 * *(uint8_t *)(v5 + 8);
          v9 = 102400;
          if ( *(uint8_t *)(v12 + 106) )
          {
            if ( *(uint8_t *)(v12 + 106) == 2 )
              v9 = *(uint16_t *)(v12 + 222) << 10;
            result = scan_adv_report(v12, v11 + v9, 0);
            v5 = *((uint32_t *)v1 + 4);
            if ( !v5 )
              break;
          }
          else
          {
            result = scan_adv_report(v12, v11 + *(uint32_t *)(v7 + 696 * *(uint8_t *)(v12 + 116) + 8), 0);
            v5 = *((uint32_t *)v1 + 4);
            if ( !v5 )
              break;
          }
        }
      }
      if ( *((uint32_t *)v1 + 11) )
      {
        if ( **(int16_t **)off_1274B0 < 0 && (v1[88] & 0xC) == 0 )
          return mmio_irq_clear(dword_1274B8, dword_1274B4, 1698);
      }
      else
      {
        return set_tx_buffer(v2);
      }
    }
  }
  else
  {
    *((uint8_t *)off_1274A8 + 88) &= ~0x40u;
  }
  return result;
}

