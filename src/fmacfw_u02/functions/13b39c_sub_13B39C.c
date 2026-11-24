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


extern uint32_t dword_13B554;
extern uint32_t dword_13B558;
extern uint32_t dword_13B55C;
extern uint32_t dword_13B560;
extern uint32_t off_13B53C;
extern uint32_t off_13B540;
extern uint32_t off_13B54C;
extern uint32_t off_13B550;

// adv_pdu_scan_req_handler @ 0x13b39c, size 414 bytes
int  adv_pdu_scan_req_handler(int a1, char *a2, unsigned int a3)
{
  char *v6; // r8
  char v7; // r10
  volatile unsigned int v8; // r3
  char v9; // r5
  char v10; // r6
  char *v11; // r0
  uint16_t v12; // r3
  char *v13; // r5
  volatile unsigned int v14; // r3

  if ( rx_rate_field_parse(a3) == 3 )
  {
    v6 = (char *)off_13B540 + 32 * (a3 >> 8);
    if ( v6[17] )
    {
      if ( v6[17] == 1 )
      {
        if ( a2[2] )
        {
          rf_get_chan_state(a3 >> 8);
          cmd_handler_a(dword_13B55C, v6);
          rx_phy_status_parse(a3, 0);
        }
        else
        {
          v7 = v6[20];
          reset_tx_descriptor((int)off_13B540 + 32 * (a3 >> 8));
          v8 = (*(volatile uint32_t *)0x40501010u);
          *((uint32_t *)v6 + 2) = v8;
          v9 = *a2;
          v10 = a2[1];
          v11 = (char *)ke_msg_alloc(5131, 13, 5, 3);
          v11[2] = v7 - 4;
          *v11 = v9;
          v11[1] = v10;
          ke_msg_send_2((int)v11);
          rf_set_freq(a3 >> 8);
          rx_phy_status_parse(a3, 1);
        }
      }
      else if ( **(uint16_t **)off_13B53C < 0 )
      {
        call_shared_handler(off_13B54C, (int)aMmBaAddCfmHand, 218);
      }
    }
    else
    {
      v12 = HIBYTE(((uint32_t *)(uintptr_t)off_13B550)[92]);
      if ( HIBYTE(((uint32_t *)(uintptr_t)off_13B550)[92]) )
        v12 = *(uint8_t *)(dword_13B558
                                 + 1320
                                 * *(uint8_t *)(dword_13B554 + 696 * *((uint8_t *)off_13B540 + 16) + 34)
                                 + 106) == 0;
      v13 = (char *)off_13B540 + 32 * (a3 >> 8);
      if ( a2[2] )
      {
        adv_set_params(
          (uint8_t)v13[16],
          (int)v13,
          1,
          (uint8_t)v13[23],
          v12 | (4 * (uint8_t)v13[22]) | (2 * (uint8_t)v13[18]) | (*((uint16_t *)v13 + 10) << 6),
          0x25u,
          0);
        cmd_handler_a(dword_13B560, v13);
        rx_phy_status_parse(a3, 0);
      }
      else
      {
        adv_set_params(
          (uint8_t)v13[16],
          (int)v13,
          1,
          (uint8_t)v13[23],
          v12 | (4 * (uint8_t)v13[22]) | (2 * (uint8_t)v13[18]) | (*((uint16_t *)v13 + 10) << 6),
          (uint8_t)a2[2],
          (uint8_t)a2[2]);
        *(uint8_t *)(696 * (uint8_t)*a2 + 12 * (uint8_t)a2[1] + dword_13B554 + 452) = BYTE1(a3);
        v14 = (*(volatile uint32_t *)0x40501010u);
        *((uint32_t *)v13 + 2) = v14;
        rf_set_freq(a3 >> 8);
        rx_phy_status_parse(a3, 1);
      }
    }
    return 0;
  }
  if ( **(uint16_t **)off_13B53C >= 0 )
    return 0;
  call_shared_handler(off_13B54C, (int)aMmBaAddCfmHand, 109);
  return 0;
}
