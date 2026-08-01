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

extern uint32_t off_133BC8;
extern uint32_t dword_133BE0;
extern uint32_t dword_133BDC;
extern uint32_t off_133BCC;
extern uint32_t off_133BD0;
extern uint32_t dword_133BD4;
extern uint32_t dword_133BD8;

// main_loop_check @ 0x133abc, size 266 bytes
// Doc: main_loop_check [rf]: Load RF parameter pointer and check for non-zero value
// main_loop_check [rf]: Load RF parameter pointer and check for non-zero value
int main_loop_check()
{
  int v0; // r2
  unsigned int v1; // r3
  uint8_t *v2; // r3
  uint8_t *v4; // r4
  int v5; // r3
  int v6; // r1
  int v7; // [sp+0h] [bp-Ch] BYREF
  int v8; // [sp+4h] [bp-8h] BYREF

  if ( **(int16_t **)off_133BC8 < 0 && rx_rate_field_parse(6u) != 4 && rx_rate_field_parse(6u) != 10 )
    mmio_clear_register(dword_133BE0, dword_133BDC, 697);
  if ( rx_rate_field_parse(6u) == 10 )
  {
    v4 = off_133BCC;
    v5 = *((uint8_t *)off_133BCC + 4);
    *(uint32_t *)(*((uint32_t *)off_133BCC + 2) + 472) = 0;
    if ( v5 )
    {
      ke_msg_send_no_param(6148, 13, 6);
      v4[4] = 0;
    }
    ke_msg_send(*(uint32_t *)v4 + 12);
    v6 = (uint8_t)v4[33];
    *(uint32_t *)v4 = 0;
    if ( v6 )
    {
      v7 = 0;
      v8 = 0;
      get_controller_state(&v7, &v8);
      rx_packet_handler(v7, v8, 0);
    }
    else
    {
      rx_phy_status_parse(6u, 0);
    }
    return 0;
  }
  else
  {
    v0 = *((uint32_t *)off_133BCC + 4);
    v1 = *(uint8_t *)(v0 + 59);
    if ( v1 == 2 )
    {
      if ( (*(uint32_t *)(v0 + 48) & 0x40) != 0 )
      {
        init_rf_tables();
        v2 = off_133BD0;
        if ( *((uint8_t *)off_133BD0 + 13) )
        {
LABEL_6:
          if ( (v2[15] & 1) != 0 )
          {
            ke_task_create(6155, 6, dword_133BD4);
            mmio_set_control_bit_26();
          }
        }
        return 0;
      }
LABEL_5:
      bt_get_profile_by_id(1, 0);
      v2 = off_133BD0;
      if ( *((uint8_t *)off_133BD0 + 13) )
        goto LABEL_6;
      return 0;
    }
    if ( v1 <= 2 )
      goto LABEL_5;
    if ( v1 == 3 )
    {
      bt_get_current_profile_conn(dword_133BD8);
      if ( *((uint8_t *)off_133BD0 + 13) )
        *((uint8_t *)off_133BD0 + 15) |= 2u;
      return 0;
    }
    bt_setup_conn_profile(1);
    return 0;
  }
}

