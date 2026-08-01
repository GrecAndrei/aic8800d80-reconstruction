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

extern uint32_t off_1345B4;
extern uint32_t off_1345B8;
extern uint32_t off_1345BC;

// send_hci_packet @ 0x1344c0, size 242 bytes
uint32_t * send_hci_packet(int a1, int a2)
{
  int *v4; // r5
  int v5; // r0
  int v6; // r4
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int16_t v15; // r3
  int v16; // r5
  int v17; // r0
  int v18; // r3
  int v19; // r0
  int v20; // r2
  uint32_t v21[2]; // [sp+8h] [bp-8h]

  v4 = *((int **)off_1345B4 + 4);
  v5 = ke_msg_alloc(4096, 4, 6, 0x178u);
  *(uint8_t *)(v5 + 366) = *((uint8_t *)v4 + 61);
  v6 = v5;
  v7 = *v4;
  v8 = v4[1];
  v9 = v4[2];
  v10 = v4[3];
  v4 += 4;
  *(uint32_t *)(v6 + 360) = 0;
  *(uint16_t *)(v6 + 364) = 0;
  *(uint32_t *)(v6 + 252) = v7;
  *(uint32_t *)(v6 + 256) = v8;
  *(uint32_t *)(v6 + 260) = v9;
  *(uint32_t *)(v6 + 264) = v10;
  v11 = v4[1];
  v12 = v4[2];
  v13 = v4[3];
  *(uint32_t *)(v6 + 268) = *v4;
  *(uint32_t *)(v6 + 272) = v11;
  *(uint32_t *)(v6 + 276) = v12;
  *(uint32_t *)(v6 + 280) = v13;
  *(uint8_t *)(v6 + 284) = v4[4];
  *(uint8_t *)(v6 + 368) = 1;
  if ( a1 )
  {
    *(uint32_t *)(v6 + 352) = *(uint32_t *)a1;
    *(uint16_t *)(v6 + 356) = *(uint16_t *)(a1 + 4);
    if ( a2 )
    {
LABEL_3:
      *(uint32_t *)v6 = *(uint32_t *)a2;
      *(uint16_t *)(v6 + 4) = *(uint16_t *)(a2 + 4);
      *(uint8_t *)(v6 + 367) = 1;
      goto LABEL_4;
    }
  }
  else
  {
    v15 = *((uint16_t *)off_1345B8 + 2);
    *(uint32_t *)(v6 + 352) = *(uint32_t *)off_1345B8;
    *(uint16_t *)(v6 + 356) = v15;
    if ( a2 )
      goto LABEL_3;
  }
  v21[0] = off_1345BC;
  v16 = *((uint8_t *)off_1345BC + 253);
  v17 = *((uint8_t *)off_1345BC + 252);
  v21[1] = (char *)off_1345BC + 84;
  *(uint8_t *)(v6 + 367) = a2;
  while ( 1 )
  {
    if ( v17 )
    {
      v18 = v21[a2];
      v19 = 6 * (int16_t)v17 + v18;
      do
      {
        if ( (*(uint8_t *)(v18 + 3) & 2) == 0 )
        {
          v20 = *(uint8_t *)(v6 + 367);
          *(uint8_t *)(v6 + 367) = v20 + 1;
          v20 *= 3;
          *(uint32_t *)(v6 + 2 * v20) = *(uint32_t *)v18;
          *(uint16_t *)(v6 + 2 * v20 + 4) = *(uint16_t *)(v18 + 4);
        }
        v18 += 6;
      }
      while ( v18 != v19 );
    }
    if ( a2 )
      break;
    v17 = v16;
    a2 = 1;
  }
LABEL_4:
  ke_msg_send(v6);
  return rx_phy_status_parse(6u, 1);
}

