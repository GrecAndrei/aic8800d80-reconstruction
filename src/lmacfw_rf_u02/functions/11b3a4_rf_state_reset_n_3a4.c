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

extern uint32_t off_11B4C0;
extern uint32_t dword_11B4C4;
extern uint32_t off_11B4E4;
extern uint32_t off_11B4C8;
extern uint32_t off_11B4D0;
extern uint32_t off_11B4CC;
extern uint32_t off_11B4D8;
extern uint32_t dword_11B4E0;
extern uint32_t dword_11B4DC;
extern uint32_t off_11B4D4;

// rx_queue_init @ 0x11b3a4, size 282 bytes
// Doc: rx_queue_init [rf]: RF state reset clearing context fields
// rx_queue_init [rf]: RF state reset clearing context fields
int  rx_queue_init(int result, int a2, int a3)
{
  uint8_t *v3; // r6
  int v4; // r4
  int v6; // r3
  int v7; // zf
  int v8; // r3
  uint16_t *v9; // r8
  uint16_t *v10; // r0
  uint16_t *v11; // r7
  int v12; // r0
  int v13; // r2
  unsigned int *v14; // r12
  uint32_t *v15; // r1
  char v16; // r3
  uint32_t *v17; // r7
  int v18; // r2
  unsigned int v19; // r3

  v3 = off_11B4C0;
  v4 = result;
  *((uint32_t *)off_11B4C0 + 10) = 0;
  if ( a2 )
  {
    v6 = *(uint8_t *)(result + 24);
    if ( v6 != 3 )
      goto LABEL_3;
  }
  else
  {
    result = rf_state_process(result, 0, a3);
    v6 = *(uint8_t *)(v4 + 24);
    if ( v6 != 3 )
    {
LABEL_3:
      v7 = v6 == 4;
      v8 = (uint8_t)v3[88];
      if ( v7 )
      {
        v3[88] = v8 & 0xFB;
        if ( *(uint16_t *)(v4 + 14) )
        {
          result = send_hci_event(v4);
          v8 = (uint8_t)v3[88];
        }
        else
        {
          v8 &= 0xDBu;
        }
      }
      goto LABEL_4;
    }
  }
  v3[88] &= ~8u;
  v9 = (uint16_t *)rf_get_tx_entry();
  v10 = (uint16_t *)ke_msg_send(79, 4, 0, 12);
  *v10 = *v9;
  v11 = v10;
  v12 = rf_get_tx_power(v9);
  v13 = dword_11B4C4;
  v14 = (unsigned int *)off_11B4E4;
  v15 = off_11B4C8;
  *((uint32_t *)v11 + 1) = (unsigned int)(((unsigned int)dword_11B4C4 * (unsigned uint64_t)(unsigned int)v12) >> 32) >> 6;
  *((uint32_t *)v11 + 2) = (unsigned int)(((unsigned int)v13 * (unsigned uint64_t)*v14) >> 32) >> 6;
  *((uint8_t *)v11 + 2) = 0;
  v16 = 10;
  while ( 1 )
  {
    --v16;
    if ( (uint8_t)*v15 )
      break;
    if ( !v16 )
      goto LABEL_13;
  }
  *((uint8_t *)v11 + 2) = *v15;
LABEL_13:
  rx_irq_handler(v11);
  v17 = off_11B4D0;
  v18 = **(int16_t **)off_11B4CC;
  v19 = *((uint32_t *)off_11B4D0 + 1) & 0xFFFFDDFF;
  *((uint32_t *)off_11B4D0 + 1) = v19;
  if ( v18 < 0 && *(uint32_t *)off_11B4D8 << 28 )
  {
    flash_cmd_exec(dword_11B4E0, dword_11B4DC, 472);
    v19 = v17[1];
  }
  *(uint32_t *)off_11B4D4 = v19 | *v17;
  result = ke_evt_handler(142, 2, 255);
  v8 = (uint8_t)v3[88];
LABEL_4:
  *(uint8_t *)(v4 + 24) = -1;
  v3[88] = v8 & 0xEF;
  if ( !(v8 << 30) )
  {
    if ( a2 )
      return result;
    return rf_packet_available();
  }
  result = rf_flag_set();
  if ( !a2 )
    return rf_packet_available();
  return result;
}

