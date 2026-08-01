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

extern uint32_t dword_13B368;
extern uint32_t dword_13B35C;
extern uint32_t off_13B38C;
extern uint32_t dword_13B374;
extern uint32_t dword_13B378;
extern uint32_t dword_13B36C;
extern uint32_t dword_13B370;
extern uint32_t dword_13B37C;
extern uint32_t off_13B380;
extern uint32_t off_13B360;
extern uint32_t dword_13B364;
extern uint32_t dword_13B384;
extern uint32_t off_13B388;

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
  unsigned int v13; // r7
  unsigned int v14; // r10
  int v15; // r8
  int v16; // r9
  int v17; // r3
  int v18; // r8
  unsigned int v19; // r8
  int16_t v20; // r3
  unsigned int v21; // r2
  unsigned int v22; // r7
  int v23; // r0
  unsigned int v24; // r1
  int v25; // r2
  int v26; // r3
  int v27; // r5
  int v28; // r3
  int v29; // [sp+14h] [bp-10h]
  uint32_t *v30; // [sp+14h] [bp-10h]
  uint32_t *v31; // [sp+1Ch] [bp-8h]

  v3 = *(uint8_t *)(a2 + 13);
  v6 = a2 + 12;
  v7 = a3 >> 8;
  if ( v3 == 1 )
  {
    v9 = *(uint16_t *)(a2 + 17);
    if ( rx_rate_field_parse(a3) != 2 )
      return 0;
    v10 = dword_13B368;
    ke_int_lock(0x2000, a3);
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
    v25 = *((uint8_t *)off_13B38C + 377);
    v26 = v10 + v12;
    if ( v25 != 1 )
    {
      if ( v25 != 2 )
      {
        *(uint8_t *)(v26 + 24) = v9 & 1;
LABEL_38:
        v23 = *(uint8_t *)(a2 + 7);
        v24 = v7;
LABEL_31:
        rf_ctrl_send(v23, v24);
        rx_phy_status_parse(a3, 3);
        return 0;
      }
      LOBYTE(v25) = 0;
    }
    *(uint8_t *)(v26 + 24) = v25;
    goto LABEL_38;
  }
  if ( v3 == 2 )
  {
    if ( rx_rate_field_parse(a3) != 4 )
    {
      if ( rx_rate_field_parse(a3) == 1 || rx_rate_field_parse(a3) == 3 )
      {
        rx_phy_status_parse(a3, 4);
        v30 = (uint32_t *)(dword_13B368 + 32 * v7);
        if ( v7 > 0xF )
        {
          cmd_handler_c(dword_13B374, (uint32_t *)(dword_13B368 + 32 * v7));
          cmd_handler_a(dword_13B378, v30);
        }
        else
        {
          cmd_handler_c(dword_13B36C, (uint32_t *)(dword_13B368 + 32 * v7));
          cmd_handler_a(dword_13B370, v30);
        }
        rf_phy_write(*(uint8_t *)(a2 + 7), v7);
        return 0;
      }
      *(uint32_t *)(696 * *(uint8_t *)(dword_13B368 + 32 * v7 + 16)
                + 12 * *(uint8_t *)(dword_13B368 + 32 * v7 + 22)
                + dword_13B37C
                + 448) = *((uint32_t *)off_13B380 + 4);
      rf_set_channel(v7);
    }
    return 0;
  }
  if ( *(uint8_t *)(a2 + 13) )
    return 0;
  v13 = *(uint16_t *)(a2 + 15);
  v14 = (v13 >> 2) & 0xF;
  if ( v14 > 8 )
    return 0;
  v15 = *(uint8_t *)off_13B360;
  if ( *(uint8_t *)off_13B360 )
    return 0;
  v16 = *(uint8_t *)(a2 + 7);
  v29 = *(uint8_t *)(a2 + 14);
  check_status_bits(2048, dword_13B364, (v13 >> 2) & 0xF);
  if ( !phy_read_offset_b(v16, (v13 >> 2) & 0xF) )
  {
    if ( rx_rate_field_parse(a3) == 4 )
      return 2;
    v18 = dword_13B368;
    v31 = (uint32_t *)(dword_13B368 + 32 * v7);
    if ( mem_word_cmp((uint32_t **)dword_13B384, v31) )
      cmd_handler_c(dword_13B384, v31);
    v19 = v18 + 32 * v7;
    *(uint8_t *)(v19 + 22) = v14;
    *(uint8_t *)(v19 + 16) = v16;
    *(uint8_t *)(v19 + 23) = v29;
    *(uint8_t *)(v19 + 18) = (v13 & 2) != 0;
    *(uint8_t *)(v19 + 17) = 0;
    v20 = *(uint16_t *)(v6 + 5);
    v21 = *(uint16_t *)(v6 + 7);
    *(uint16_t *)(v19 + 14) = v20;
    v22 = v13 >> 6;
    if ( v22 >= 0x40 )
      LOWORD(v22) = 64;
    *(uint16_t *)(v19 + 20) = v22;
    *(uint16_t *)(v19 + 12) = v21 >> 4;
    *(uint32_t *)(v19 + 4) = 0;
    if ( !v20 )
      *(uint16_t *)(v19 + 14) = *(uint16_t *)(*(uint32_t *)off_13B388 + 2);
    v23 = (uint16_t)v16;
    v24 = v7;
    goto LABEL_31;
  }
  if ( rx_rate_field_parse(a3) == 1 )
  {
    v27 = dword_13B368 + 32 * v7;
    v28 = v13 >> 6;
    if ( v13 >> 6 >= 0x40 )
      v28 = 64;
    if ( *(uint16_t *)(v27 + 20) == v28 )
    {
      v17 = v15;
    }
    else
    {
      rx_phy_status_parse(a3, 4);
      cmd_handler_c(dword_13B36C, (uint32_t *)v27);
      cmd_handler_a(dword_13B370, (uint32_t *)v27);
      rf_phy_write((uint16_t)v16, v7);
      v17 = 37;
    }
  }
  else
  {
    v17 = 37;
  }
  adv_set_params(v16, 0, 1, v29, v13, v17, 0);
  return 0;
}

