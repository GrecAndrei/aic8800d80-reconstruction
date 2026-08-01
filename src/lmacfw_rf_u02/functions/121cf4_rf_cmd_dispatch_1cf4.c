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

extern uint32_t off_121E2C;
extern uint32_t dword_121E38;

// co_list_insert @ 0x121cf4, size 304 bytes
// Doc: rf_cmd_dispatch_table [rf]: Dispatches RF command via table with size bounds 0x60/0x7f
// rf_cmd_dispatch_table [rf]: Dispatches RF command via table with size bounds 0x60/0x7f
int  co_list_insert(unsigned int a1, uint8_t *a2, int a3)
{
  int *v3; // r6
  char v4; // r4
  int *v6; // r7
  uint32_t *v7; // r3
  int v8; // r2
  int *v9; // r8
  int result; // r0
  int v11; // r0
  int *v12; // r2
  uint32_t *v13; // r3
  int *v14; // r8
  int v15; // r1
  unsigned int v16; // r0
  uint8_t *v17; // r0
  int v18; // r2
  int v19; // r3
  unsigned int v20; // r1
  uint8_t *v21; // r0
  uint32_t *v22; // r3
  uint8_t *v23; // r3
  int v24; // r2

  v3 = (int *)rf_mem_write_1e24;
  v4 = a1;
  if ( *(uint32_t *)rf_mem_write_1e24 )
  {
    if ( !a3 )
      goto rf_cmd_queue_next_n_42b;
rf_cmd_dispatch_n_1f0:
    v11 = memset_ff(a3);
    v12 = (int *)rf_state_check_n_20c;
    v13 = rf_cmd_dispatch_e30;
    *v3 = (int)a2;
    *v12 = v11;
    *v13 = 0;
    return 0;
  }
  *(uint32_t *)rf_mem_write_1e24 = a2;
  if ( a3 )
    goto rf_cmd_dispatch_n_1f0;
rf_cmd_queue_next_n_42b:
  v6 = (int *)rf_state_check_n_20c;
  v7 = off_121E2C;
  v8 = *(uint32_t *)rf_state_check_n_20c;
  *(uint32_t *)off_121E2C = *(uint32_t *)rf_state_check_n_20c;
  if ( a1 <= 0x17 )
  {
    switch ( a1 )
    {
      case 0u:
        return -1;
      case 3u:
        result = 0;
        *a2 = 0;
        return result;
      case 8u:
        goto rf_mem_write_n_28c;
      case 0xAu:
      case 0xDu:
        v21 = (uint8_t *)rf_mem_write_n_1f7;
        *(uint8_t *)*v3 = 0;
        uart_tx_string(v21);
        return *v3 - (uint32_t)a2;
      case 0x15u:
        v22 = rf_cmd_dispatch_e30;
        *v3 = (int)a2;
        *v22 = 0;
        return -1;
      case 0x17u:
        v14 = (int *)rf_cmd_dispatch_e30;
        v15 = *v3;
        if ( *(uint32_t *)rf_cmd_dispatch_e30 )
        {
          v16 = (unsigned int)a2;
          while ( 1 )
          {
            v17 = (uint8_t *)tlv_find(v16, v15, v8);
            v18 = *v14;
            *v3 = (int)v17;
            v15 = (int)v17;
            if ( v18 <= 0 )
              break;
            v19 = *v17;
            v16 = (unsigned int)a2;
            if ( v19 == 32 )
              break;
            v8 = *v6;
          }
        }
        return -1;
      default:
        v9 = (int *)rf_cmd_dispatch_e30;
        if ( *(int *)rf_cmd_dispatch_e30 > 61 )
          goto rf_cmd_dispatch_n_204;
        if ( a1 != 9 )
          goto rf_mem_write_n_213;
        uart_tx_string((uint8_t *)(dword_121E38 + (v8 & 7)));
        *(uint32_t *)off_121E2C = (*(uint32_t *)off_121E2C & 0xFFFFFFF8) + 8;
        break;
    }
    goto rf_mem_write_n_22b;
  }
  if ( a1 == 127 )
  {
rf_mem_write_n_28c:
    v20 = *v3;
    if ( *(uint32_t *)rf_cmd_dispatch_e30 )
      v20 = tlv_find((unsigned int)a2, v20, v8);
    *v3 = v20;
    return -1;
  }
  else
  {
    v9 = (int *)rf_cmd_dispatch_e30;
    if ( *(int *)rf_cmd_dispatch_e30 <= 61 )
    {
rf_mem_write_n_213:
      *v7 = v8 + 1;
      uart_tx_byte(a1);
rf_mem_write_n_22b:
      v23 = (uint8_t *)*v3;
      *v23 = v4;
      v24 = *v9 + 1;
      *v3 = (int)(v23 + 1);
      *v9 = v24;
      return -1;
    }
rf_cmd_dispatch_n_204:
    uart_tx_byte(7);
    return -1;
  }
}

