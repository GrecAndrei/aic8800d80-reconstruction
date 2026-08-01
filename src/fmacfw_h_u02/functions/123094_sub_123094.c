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

extern uint32_t off_123194;
extern uint32_t dword_123198;
extern uint32_t dword_1231A0;
extern uint32_t dword_1231A4;
extern uint32_t dword_1231A8;
extern uint32_t dword_1231AC;
extern uint32_t dword_12319C;

// ke_send_msg_88 @ 0x123094, size 254 bytes
int  ke_send_msg_88(int a1, int *a2, int a3, int a4)
{
  int v5; // r6
  int v6; // r0
  int v7; // r2
  int v8; // r4
  int v9; // r1
  int v10; // r0
  int result; // r0
  int v12; // r2
  int v13; // r0
  int v14; // r1
  uint32_t *v15; // r6
  int v16; // r3
  int v17; // r1
  int v18; // r2
  int v19; // r0
  uint8_t *v20; // r5
  char v21; // r0
  int v22; // r1
  uint32_t *v23; // r5
  int v24; // r0
  int v25; // r0
  int v26; // r1

  v5 = *a2;
  v6 = tx_send_pdu(136, a4, a3, 8);
  v8 = v6;
  *(uint32_t *)v6 = v5;
  switch ( v5 )
  {
    case 0:
      v9 = *((uint8_t *)a2 + 4);
      *((uint8_t *)off_123194 + 373) = v9;
      v10 = dword_123198;
      *(uint8_t *)(v8 + 4) = v9;
      alloc_tx_event(v10, v9, v7);
      goto LABEL_3;
    case 1:
      v15 = off_123194;
      v16 = *((uint8_t *)a2 + 4);
      v17 = *((uint8_t *)off_123194 + 363);
      *((uint8_t *)off_123194 + 363) = v16;
      v18 = a2[2];
      v15[91] = v18;
      if ( v16 != v17 )
      {
        if ( v16 )
        {
          v19 = read_global_signed_flag(v6);
          set_flag_send_event_42e(v19);
        }
        else
        {
          clear_flag_send_event_42e();
        }
        v17 = *((uint8_t *)v15 + 363);
      }
      *(uint8_t *)(v8 + 4) = v17;
      alloc_tx_event(dword_1231A0, v17, v18);
      rx_process_packet(v8);
      result = 0;
      break;
    case 2:
      v20 = (uint8_t *)off_123194;
      *(uint8_t *)(v6 + 4) = *((uint8_t *)off_123194 + 363);
      v21 = rf_power_adjust();
      *(uint8_t *)(v8 + 5) = v21;
      alloc_tx_event(dword_1231A4, v20[363], v21);
      rx_process_packet(v8);
      result = 0;
      break;
    case 3:
      v22 = a2[1];
      v23 = off_123194;
      v24 = dword_1231A8;
      *((uint32_t *)off_123194 + 98) = v22;
      alloc_tx_event(v24, v22, v7);
      *(uint32_t *)(v8 + 4) = v23[98];
      rx_process_packet(v8);
      result = 0;
      break;
    case 4:
      v25 = dword_1231AC;
      v26 = *((uint32_t *)off_123194 + 98);
      *(uint32_t *)(v8 + 4) = v26;
      alloc_tx_event(v25, v26, v7);
      rx_process_packet(v8);
      result = 0;
      break;
    case 5:
      v12 = *((uint32_t *)off_123194 + 98);
      v13 = dword_12319C;
      v14 = (a2[2] ^ v12) & a2[1] ^ v12;
      *((uint32_t *)off_123194 + 98) = v14;
      *(uint32_t *)(v8 + 4) = v14;
      alloc_tx_event(v13, v14, v12);
      rx_process_packet(v8);
      result = 0;
      break;
    default:
LABEL_3:
      rx_process_packet(v8);
      result = 0;
      break;
  }
  return result;
}

