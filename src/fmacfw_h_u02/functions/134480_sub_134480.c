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

extern uint32_t off_134584;
extern uint32_t off_134588;
extern uint32_t off_13458C;
extern uint32_t off_134594;
extern uint32_t off_134590;
extern uint32_t dword_134598;
extern uint32_t off_13459C;
extern uint32_t dword_1345A0;
extern uint32_t off_1345A4;

// ble_parse_event @ 0x134480, size 260 bytes
void  ble_parse_event(int a1, int a2, int a3)
{
  uint32_t *v4; // r3
  uint8_t *v7; // r9
  int *v8; // r10
  int v9; // r4
  int16_t v10; // lr
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r1
  int v16; // r2
  int v17; // r3
  uint32_t *v18; // r6
  uint32_t *v19; // r4
  unsigned int v20; // r2

  v4 = off_134584;
  if ( !*(uint8_t *)(a2 + 2)
    && *((uint8_t *)off_134584 + 1)
    && *(int *)off_134588 < 0
    && (*((uint32_t *)off_13458C + 75) & 0x80) != 0 )
  {
    if ( *((uint8_t *)off_134584 + 14) == 1 )
    {
      v18 = off_134594;
      *(uint32_t *)off_134590 = dword_134598;
      v19 = off_13459C;
      *v18 &= 0xFFFFFFF0;
      *v19 &= ~0x80000000;
      v4[1] = a1;
      v4[2] = a2;
      *((uint8_t *)v4 + 12) = a3;
      *((uint8_t *)v4 + 13) = 1;
      *((uint16_t *)v4 + 1) = 257;
      v20 = dword_1345A0;
      v18[35594] = 0;
      ke_event_handler(6155, 6, v20);
      enable_clock_2();
      return;
    }
    *((uint8_t *)off_134584 + 3) = 0;
  }
  else
  {
    *((uint8_t *)off_134584 + 14) = 0;
    *((uint8_t *)v4 + 13) = 0;
    *((uint8_t *)v4 + 3) = 0;
  }
  v7 = off_1345A4;
  v8 = *((int **)off_1345A4 + 4);
  v9 = tx_send_pdu(4098, 4, 6, 0x178u);
  *(uint32_t *)v9 = *(uint32_t *)a2;
  v10 = *(uint16_t *)(a2 + 4);
  *(uint8_t *)(v9 + 367) = 1;
  v11 = *v8;
  v12 = v8[1];
  v13 = v8[2];
  v14 = v8[3];
  *(uint16_t *)(v9 + 4) = v10;
  *(uint32_t *)(v9 + 252) = v11;
  *(uint32_t *)(v9 + 256) = v12;
  *(uint32_t *)(v9 + 260) = v13;
  *(uint32_t *)(v9 + 264) = v14;
  v15 = v8[5];
  v16 = v8[6];
  v17 = v8[7];
  *(uint32_t *)(v9 + 268) = v8[4];
  *(uint32_t *)(v9 + 272) = v15;
  *(uint32_t *)(v9 + 276) = v16;
  *(uint32_t *)(v9 + 280) = v17;
  *(uint8_t *)(v9 + 284) = v8[8];
  *(uint8_t *)(v9 + 368) = 1;
  *(uint16_t *)(v9 + 364) = 0;
  *(uint32_t *)(v9 + 360) = 0;
  *(uint8_t *)(v9 + 366) = *((uint8_t *)v8 + 61);
  *(uint32_t *)(v9 + 352) = *(uint32_t *)a1;
  *(uint16_t *)(v9 + 356) = *(uint16_t *)(a1 + 4);
  if ( a3 )
    *(uint8_t *)(v9 + 3) |= 1u;
  v7[32] = a3;
  rx_process_packet(v9);
  hci_cmd_preprocess(6u, 2);
}

