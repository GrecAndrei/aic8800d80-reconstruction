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

extern uint32_t off_13B540;
extern uint32_t dword_13B55C;
extern uint32_t off_13B544;
extern uint32_t off_13B53C;
extern uint32_t dword_13B54C;
extern uint32_t dword_13B548;
extern uint32_t off_13B550;
extern uint32_t dword_13B558;
extern uint32_t dword_13B554;
extern uint32_t dword_13B560;

// adv_pdu_scan_req_handler @ 0x13b39c, size 414 bytes
int  adv_pdu_scan_req_handler(int a1, char *a2, unsigned int a3)
{
  char *v6; // r8
  char v7; // r10
  char v8; // r5
  uint8_t v9; // r6
  uint8_t *v10; // r0
  uint16_t v11; // r3
  char *v12; // r5
  int v13; // r0
  int v14; // r2
  uint32_t *v15; // r6

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
          reset_tx_descriptor((char *)off_13B540 + 32 * (a3 >> 8));
          *((uint32_t *)v6 + 2) = *((uint32_t *)off_13B544 + 4);
          v8 = *a2;
          v9 = a2[1];
          v10 = (uint8_t *)ke_msg_alloc(5131, 13, 5, 3u);
          v10[2] = v7 - 4;
          *v10 = v8;
          v10[1] = v9;
          ke_msg_send((int)v10);
          rf_set_freq(a3 >> 8);
          rx_phy_status_parse(a3, 1);
        }
      }
      else if ( **(int16_t **)off_13B53C < 0 )
      {
        call_shared_handler(dword_13B54C, dword_13B548, 218);
      }
    }
    else
    {
      v11 = *((uint8_t *)off_13B550 + 371);
      if ( *((uint8_t *)off_13B550 + 371) )
        v11 = *(uint8_t *)(dword_13B558
                                 + 1320
                                 * *(uint8_t *)(dword_13B554 + 696 * *((uint8_t *)off_13B540 + 16) + 34)
                                 + 106) == 0;
      v12 = (char *)off_13B540 + 32 * (a3 >> 8);
      if ( a2[2] )
      {
        adv_set_params(
          (uint8_t)v12[16],
          v12,
          1,
          (uint8_t)v12[23],
          v11
        | (uint16_t)((4 * (uint8_t)v12[22])
                           | (2 * (uint8_t)v12[18])
                           | (*((uint16_t *)v12 + 10) << 6)),
          37,
          0);
        cmd_handler_a(dword_13B560, v12);
        rx_phy_status_parse(a3, 0);
      }
      else
      {
        adv_set_params(
          (uint8_t)v12[16],
          v12,
          1,
          (uint8_t)v12[23],
          v11
        | (uint16_t)((4 * (uint8_t)v12[22])
                           | (2 * (uint8_t)v12[18])
                           | (*((uint16_t *)v12 + 10) << 6)),
          (uint8_t)a2[2],
          (uint8_t)a2[2]);
        v13 = (uint8_t)*a2;
        v14 = (uint8_t)a2[1];
        v15 = off_13B544;
        *(uint8_t *)(696 * v13 + 12 * v14 + dword_13B554 + 452) = BYTE1(a3);
        *((uint32_t *)v12 + 2) = v15[4];
        rf_set_freq(a3 >> 8);
        rx_phy_status_parse(a3, 1);
      }
    }
    return 0;
  }
  if ( **(int16_t **)off_13B53C >= 0 )
    return 0;
  call_shared_handler(dword_13B54C, dword_13B548, 109);
  return 0;
}

