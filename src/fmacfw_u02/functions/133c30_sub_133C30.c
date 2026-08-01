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

extern uint32_t off_133DD4;
extern uint32_t off_133DD0;
extern uint32_t dword_133DE4;
extern uint32_t dword_133DE0;
extern uint32_t dword_133DE8;
extern uint32_t off_133DD8;
extern uint32_t off_133DDC;

// adv_state_handler @ 0x133c30, size 414 bytes
int adv_state_handler()
{
  uint8_t *v0; // r6
  int v1; // r7
  int v2; // r5
  int v3; // r8
  int v4; // r4
  int v5; // r9
  int v6; // r3
  unsigned int v8; // r3
  int v9; // r2
  int v10; // r3
  int v11; // r6
  int v12; // r0
  int16_t v13; // r2
  int v14; // r3
  int v15; // r10
  uint32_t *v16; // r1
  int v17; // r2
  int v18; // r0
  int v19; // [sp+18h] [bp-Ch] BYREF
  uint32_t v20[2]; // [sp+1Ch] [bp-8h] BYREF

  v0 = off_133DD4;
  v1 = *((uint32_t *)off_133DD4 + 4);
  if ( **(int16_t **)off_133DD0 < 0 && rx_rate_field_parse(6u) != 2 )
    mmio_clear_register(dword_133DE4, dword_133DE0, 344);
  v2 = *(uint8_t *)(v1 + 61);
  v3 = dword_133DE8;
  v4 = 1320 * v2;
  v5 = dword_133DE8 + 1320 * v2;
  if ( *(int *)(v5 + 472) < 0 )
  {
    if ( bt_get_conn_by_handle(v20) )
    {
      bt_setup_conn_profile(1);
    }
    else
    {
      v11 = ke_msg_alloc(10, 0, 6, 0x20u);
      sta_lookup_by_bss(*(uint8_t *)(v1 + 61), LOBYTE(v20[0]));
      *(uint32_t *)v11 = 0;
      *(uint8_t *)(v11 + 25) = *(uint8_t *)(v1 + 61);
      v12 = *(uint32_t *)(v5 + 368);
      v13 = *(uint16_t *)(v5 + 372);
      *(uint8_t *)(v11 + 26) = 0;
      *(uint8_t *)(v11 + 29) = *(uint8_t *)(v5 + 407);
      *(uint8_t *)(v11 + 30) = *(uint8_t *)(v5 + 408);
      v14 = *(uint32_t *)(v5 + 472);
      *(uint32_t *)(v11 + 18) = v12;
      v15 = v14 & 2;
      *(uint16_t *)(v11 + 22) = v13;
      if ( (v14 & 2) != 0 )
      {
        v15 = v14 & 4;
        if ( (v14 & 4) != 0 )
        {
          v18 = extract_9bit_field(v4 + 368 + v3);
          v14 = *(uint32_t *)(v5 + 472);
          v16 = (uint32_t *)(v4 + 280 + v3);
          v15 = v18;
        }
        else
        {
          v16 = 0;
        }
        v17 = v14 & 8;
        if ( (v14 & 8) != 0 )
          v17 = v4 + 292 + v3;
        util_init_outputs(v4 + 248 + v3, v16, v17, (uint16_t *)(v11 + 16), (int *)(v11 + 8), (int *)(v11 + 4), (char *)(v11 + 24));
      }
      *(uint32_t *)(v11 + 12) = v15;
      ke_msg_send(v11);
      rx_phy_status_parse(6u, 3);
    }
    v9 = *(uint32_t *)(v1 + 48);
    v10 = v3 + 1320 * v2;
    *(uint32_t *)(v10 + 1208) = v9;
    if ( (v9 & 4) != 0 )
    {
      *(uint32_t *)(v10 + 472) &= 0xFFFFFFF1;
      return 0;
    }
    return 0;
  }
  v6 = (uint8_t)v0[32];
  if ( v0[32] )
  {
    bt_setup_conn_profile(1);
    return 0;
  }
  v19 = (uint8_t)v0[32];
  v20[0] = v6;
  get_controller_state(&v19, v20);
  if ( *(uint8_t *)off_133DD8 != 1 && *((uint8_t *)off_133DDC + 3) != 1 )
  {
    *((uint8_t *)off_133DDC + 32) = 2;
LABEL_7:
    rx_packet_handler(v19, v20[0], 1);
    return 0;
  }
  v8 = (uint8_t)(*((uint8_t *)off_133DDC + 32) + 1);
  *((uint8_t *)off_133DDC + 32) = v8;
  if ( v8 > 1 )
    goto LABEL_7;
  rx_packet_handler(v19, v20[0], 0);
  return 0;
}

