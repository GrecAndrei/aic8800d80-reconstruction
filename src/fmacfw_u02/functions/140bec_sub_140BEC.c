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

extern uint32_t dword_140D88;
extern uint32_t dword_140D84;
extern uint32_t dword_140D8C;
extern uint32_t off_140D90;
extern uint32_t dword_140D98;
extern uint32_t dword_140D94;

// ble_ll_adv_reset @ 0x140bec, size 408 bytes
// Doc: sub_1240BEC [unknown]: Worker function with r4-r11/lr saved, takes r0,r1 args
// sub_1240BEC [unknown]: Worker function with r4-r11/lr saved, takes r0,r1 args
int  ble_ll_adv_reset(int a1, int a2)
{
  int v3; // r5
  int v4; // r7
  int *v5; // r0
  uint64_t v6; // r0
  int v7; // r8
  int v8; // r7
  int v9; // r5
  int v10; // r9
  uint32_t *v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r3
  int v15; // r2
  char *v16; // r0
  char *v17; // r5
  int v18; // r6
  int v19; // r2

  if ( a2 )
  {
    v3 = dword_140D88;
    zero_8_bytes((uint32_t *)dword_140D84);
    v4 = v3 + 6336;
    do
    {
      *(uint16_t *)(v3 - 2) = 0;
      v5 = (int *)v3;
      v3 += 528;
      memset(v5, 0, 6u);
    }
    while ( v4 != v3 );
    LODWORD(v6) = util_unknown();
    *(uint64_t *)(a1 + 40) = v6;
    *(uint32_t *)(a1 + 96) = 0;
  }
  v7 = dword_140D8C;
  v8 = dword_140D84;
LABEL_6:
  while ( rx_rate_field_parse(0xBu) == 1 )
  {
    v9 = dword_140D8C;
    v10 = dword_140D8C + 6336;
    do
    {
      while ( *(uint16_t *)(v9 + 4) != 1 || !ble_ll_adv_set_params((uint16_t *)(v9 + 6), v9 + 28, a1) )
      {
        v9 += 528;
        if ( v9 == v10 )
          goto LABEL_12;
      }
      v11 = (uint32_t *)v9;
      *(uint16_t *)(v9 + 24) = 0;
      *(uint8_t *)(v9 + 22) = 0;
      *(uint16_t *)(v9 + 4) = 2;
      v9 += 528;
      cmd_handler_a(v8, v11);
    }
    while ( v9 != v10 );
LABEL_12:
    v12 = *(uint8_t *)(a1 + 101);
    v13 = *(uint32_t *)(a1 + 96) + 1;
    *(uint32_t *)(a1 + 96) = v13;
    if ( v13 >= v12 )
    {
      if ( **(int16_t **)off_140D90 < 0 && ble_ll_adv_chk_active() )
      {
        if ( *(uint32_t *)(a1 + 92) )
          mmio_clear_register(dword_140D98, dword_140D94, 1585);
      }
      rx_phy_status_parse(0xBu, 2);
      return ble_ll_adv_sm_check(a1, 0);
    }
    rx_phy_status_parse(0xBu, 3);
    if ( !ble_ll_adv_chk_active() )
      return ble_ll_adv_sm_check(a1, 0);
  }
  rx_phy_status_parse(0xBu, 1);
  v14 = *(uint32_t *)(a1 + 96);
  while ( 1 )
  {
    v16 = rf_channel_freq((char *)*(uint8_t *)(a1 + 100), *(uint8_t *)(v14 + a1 + 102));
    v17 = v16;
    if ( v16 )
    {
      if ( (v16[3] & 2) == 0 )
        break;
    }
    v15 = *(uint8_t *)(a1 + 101);
    v14 = *(uint32_t *)(a1 + 96) + 1;
    *(uint32_t *)(a1 + 96) = v14;
    if ( v14 >= v15 )
      goto LABEL_6;
  }
  v18 = ke_msg_alloc(4096, 4, 11, 0x178u);
  *(uint32_t *)v18 = *(uint32_t *)v17;
  *(uint16_t *)(v18 + 4) = *((uint16_t *)v17 + 2);
  if ( !*(uint8_t *)(a1 + 3) )
    *(uint8_t *)(v18 + 3) |= 1u;
  *(uint8_t *)(v18 + 367) = 1;
  v19 = *(uint8_t *)(a1 + 58);
  *(uint8_t *)(v18 + 252) = v19;
  memcpy(v18 + 253, a1 + 59, v19);
  *(uint8_t *)(v18 + 368) = 1;
  *(uint16_t *)(v18 + 352) = *(uint16_t *)(a1 + 52);
  *(uint16_t *)(v18 + 354) = *(uint16_t *)(a1 + 54);
  *(uint16_t *)(v18 + 356) = *(uint16_t *)(a1 + 56);
  *(uint8_t *)(v18 + 366) = *(uint8_t *)(v7 + 6489);
  *(uint32_t *)(v18 + 372) = *(uint16_t *)(a1 + 48) << 10;
  return ke_msg_send(v18);
}

