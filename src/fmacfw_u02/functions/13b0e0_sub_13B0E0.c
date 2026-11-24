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


extern uint32_t dword_13B35C;
extern uint32_t dword_13B368;
extern uint32_t dword_13B36C;
extern uint32_t dword_13B370;
extern uint32_t dword_13B374;
extern uint32_t dword_13B378;
extern uint32_t dword_13B37C;
extern uint32_t dword_13B384;
extern uint32_t off_13B360;
extern uint32_t off_13B388;
extern uint32_t off_13B38C;

// ll_encrypt_packet @ 0x13b0e0, size 636 bytes
int  ll_encrypt_packet(int a1, int a2, unsigned int a3)
{
  int v3; // r3
  int v6; // r5
  unsigned int v7; // r6
  unsigned int v9; // r7
  int v10; // r8
  unsigned int v11; // r2
  int v12; // r11
  unsigned int a5; // r7
  unsigned int v14; // r10
  uint16_t v15; // r8
  int v16; // r9
  uint16_t v17; // r3
  int v18; // r1
  int v19; // r4
  int v20; // r2
  volatile unsigned int v21; // r1
  int v22; // r8
  unsigned int v23; // r8
  uint16_t v24; // r3
  unsigned int v25; // r2
  unsigned int v26; // r7
  char v27; // r0
  int v28; // r1
  int v29; // r2
  int v30; // r3
  int v31; // r5
  int v32; // r3
  int a4; // [sp+14h] [bp-10h]
  uint32_t *a4a; // [sp+14h] [bp-10h]
  uint32_t *a2a; // [sp+1Ch] [bp-8h]

  v3 = *(uint8_t *)(a2 + 13);
  v6 = a2 + 12;
  v7 = a3 >> 8;
  if ( v3 == 1 )
  {
    v9 = *(uint16_t *)(a2 + 17);
    if ( rx_rate_field_parse(a3) != 2 )
      return 0;
    v10 = dword_13B368;
    ke_int_lock((char *)0x2000, a3);
    v11 = v10 + 32 * v7;
    v12 = 32 * v7;
    if ( *(uint8_t *)(v11 + 23) != *(uint8_t *)(v6 + 2)
      || *(uint8_t *)(v11 + 22) != ((v9 >> 2) & 0xF)
      || *(uint16_t *)(v6 + 3) )
    {
      rf_get_chan_state(v7);
      cmd_handler_a(dword_13B35C, (uint32_t *)(v10 + v12));
      rx_phy_status_parse(a3, 0);
      return 0;
    }
    if ( *(uint16_t *)(v11 + 20) > v9 >> 6 )
      *(uint16_t *)(v11 + 20) = v9 >> 6;
    v29 = *((uint8_t *)off_13B38C + 377);
    v30 = v10 + v12;
    if ( v29 != 1 )
    {
      if ( v29 != 2 )
      {
        *(uint8_t *)(v30 + 24) = v9 & 1;
LABEL_38:
        v27 = *(uint8_t *)(a2 + 7);
        v28 = v7;
LABEL_31:
        rf_ctrl_send(v27, v28);
        rx_phy_status_parse(a3, 3);
        return 0;
      }
      LOBYTE(v29) = 0;
    }
    *(uint8_t *)(v30 + 24) = v29;
    goto LABEL_38;
  }
  if ( v3 == 2 )
  {
    if ( rx_rate_field_parse(a3) != 4 )
    {
      if ( rx_rate_field_parse(a3) == 1 || rx_rate_field_parse(a3) == 3 )
      {
        rx_phy_status_parse(a3, 4);
        a4a = (uint32_t *)(dword_13B368 + 32 * v7);
        if ( v7 > 0xF )
        {
          cmd_handler_c(dword_13B374, (uint32_t *)(dword_13B368 + 32 * v7));
          cmd_handler_a(dword_13B378, a4a);
        }
        else
        {
          cmd_handler_c(dword_13B36C, (uint32_t *)(dword_13B368 + 32 * v7));
          cmd_handler_a(dword_13B370, a4a);
        }
        rf_phy_write(*(uint8_t *)(a2 + 7), v7);
        return 0;
      }
      v18 = dword_13B368 + 32 * v7;
      v19 = *(uint8_t *)(v18 + 16);
      v20 = *(uint8_t *)(v18 + 22);
      v21 = (*(volatile uint32_t *)0x40501010u);
      *(uint32_t *)(696 * v19 + 12 * v20 + dword_13B37C + 448) = v21;
      rf_set_channel_3(v7);
    }
    return 0;
  }
  if ( *(uint8_t *)(a2 + 13) )
    return 0;
  a5 = *(uint16_t *)(a2 + 15);
  v14 = (a5 >> 2) & 0xF;
  if ( v14 > 8 )
    return 0;
  v15 = *(uint8_t *)off_13B360;
  if ( *(uint8_t *)off_13B360 )
    return 0;
  v16 = *(uint8_t *)(a2 + 7);
  a4 = *(uint8_t *)(a2 + 14);
  check_status_bits(2048, "handle addba_req:tid=%d\r\n", (a5 >> 2) & 0xF);
  if ( !phy_read_offset_b(v16, (a5 >> 2) & 0xF) )
  {
    if ( rx_rate_field_parse(a3) == 4 )
      return 2;
    v22 = dword_13B368;
    a2a = (uint32_t *)(dword_13B368 + 32 * v7);
    if ( mem_word_cmp((uint32_t **)dword_13B384, a2a) )
      cmd_handler_c(dword_13B384, a2a);
    v23 = v22 + 32 * v7;
    *(uint8_t *)(v23 + 22) = v14;
    *(uint8_t *)(v23 + 16) = v16;
    *(uint8_t *)(v23 + 23) = a4;
    *(uint8_t *)(v23 + 18) = (a5 & 2) != 0;
    *(uint8_t *)(v23 + 17) = 0;
    v24 = *(uint16_t *)(v6 + 5);
    v25 = *(uint16_t *)(v6 + 7);
    *(uint16_t *)(v23 + 14) = v24;
    v26 = a5 >> 6;
    if ( v26 >= 0x40 )
      LOWORD(v26) = 64;
    *(uint16_t *)(v23 + 20) = v26;
    *(uint16_t *)(v23 + 12) = v25 >> 4;
    *(uint32_t *)(v23 + 4) = 0;
    if ( !v24 )
      *(uint16_t *)(v23 + 14) = *(uint16_t *)(*(uint32_t *)off_13B388 + 2);
    v27 = v16;
    v28 = v7;
    goto LABEL_31;
  }
  if ( rx_rate_field_parse(a3) == 1 )
  {
    v31 = dword_13B368 + 32 * v7;
    v32 = a5 >> 6;
    if ( a5 >> 6 >= 0x40 )
      v32 = 64;
    if ( *(uint16_t *)(v31 + 20) == v32 )
    {
      v17 = v15;
    }
    else
    {
      rx_phy_status_parse(a3, 4);
      cmd_handler_c(dword_13B36C, (uint32_t *)v31);
      cmd_handler_a(dword_13B370, (uint32_t *)v31);
      rf_phy_write(v16, v7);
      v17 = 37;
    }
  }
  else
  {
    v17 = 37;
  }
  adv_set_params(v16, 0, 1, a4, a5, v17, 0);
  return 0;
}
