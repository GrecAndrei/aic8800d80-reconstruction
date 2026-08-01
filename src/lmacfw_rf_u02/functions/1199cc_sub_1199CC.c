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

extern uint32_t off_119ACC;
extern uint32_t dword_119AD0;
extern uint32_t dword_119AD8;
extern uint32_t dword_119ADC;
extern uint32_t dword_119AE0;
extern uint32_t dword_119AE4;
extern uint32_t dword_119AD4;

// ke_alloc_msg_0x88 @ 0x1199cc, size 254 bytes
// Doc: sub_12199CC [rf]: Allocates 0x88-byte context and initializes RF object
// sub_12199CC [rf]: Allocates 0x88-byte context and initializes RF object
int  ke_alloc_msg_0x88(int a1, int *a2, int a3, int a4)
{
  int v5; // r6
  int v6; // r0
  int v7; // r4
  int v8; // r1
  int v9; // r0
  int result; // r0
  int v11; // r0
  int v12; // r1
  uint32_t *v13; // r6
  int v14; // r3
  int v15; // r1
  int v16; // r0
  uint8_t *v17; // r5
  int v18; // r1
  uint32_t *v19; // r5
  int v20; // r0
  int v21; // r0
  int v22; // r1

  v5 = *a2;
  v6 = ke_msg_send(136, a4, a3, 8);
  v7 = v6;
  *(uint32_t *)v6 = v5;
  switch ( v5 )
  {
    case 0:
      v8 = *((uint8_t *)a2 + 4);
      *((uint8_t *)off_119ACC + 373) = v8;
      v9 = dword_119AD0;
      *(uint8_t *)(v7 + 4) = v8;
      dispatch_event_handler(v9, v8);
      goto LABEL_3;
    case 1:
      v13 = off_119ACC;
      v14 = *((uint8_t *)a2 + 4);
      v15 = *((uint8_t *)off_119ACC + 363);
      *((uint8_t *)off_119ACC + 363) = v14;
      v13[91] = a2[2];
      if ( v14 != v15 )
      {
        if ( v14 )
        {
          v16 = rf_read_trim(v6);
          rf_enable(v16);
        }
        else
        {
          rf_disable();
        }
        v15 = *((uint8_t *)v13 + 363);
      }
      *(uint8_t *)(v7 + 4) = v15;
      dispatch_event_handler(dword_119AD8, v15);
      rx_irq_handler(v7);
      result = 0;
      break;
    case 2:
      v17 = (uint8_t *)off_119ACC;
      *(uint8_t *)(v6 + 4) = *((uint8_t *)off_119ACC + 363);
      *(uint8_t *)(v6 + 5) = mac_packet_dispatch();
      dispatch_event_handler(dword_119ADC, v17[363]);
      rx_irq_handler(v7);
      result = 0;
      break;
    case 3:
      v18 = a2[1];
      v19 = off_119ACC;
      v20 = dword_119AE0;
      *((uint32_t *)off_119ACC + 98) = v18;
      dispatch_event_handler(v20, v18);
      *(uint32_t *)(v7 + 4) = v19[98];
      rx_irq_handler(v7);
      result = 0;
      break;
    case 4:
      v21 = dword_119AE4;
      v22 = *((uint32_t *)off_119ACC + 98);
      *(uint32_t *)(v7 + 4) = v22;
      dispatch_event_handler(v21, v22);
      rx_irq_handler(v7);
      result = 0;
      break;
    case 5:
      v11 = dword_119AD4;
      v12 = (a2[2] ^ *((uint32_t *)off_119ACC + 98)) & a2[1] ^ *((uint32_t *)off_119ACC + 98);
      *((uint32_t *)off_119ACC + 98) = v12;
      *(uint32_t *)(v7 + 4) = v12;
      dispatch_event_handler(v11, v12);
      rx_irq_handler(v7);
      result = 0;
      break;
    default:
LABEL_3:
      rx_irq_handler(v7);
      result = 0;
      break;
  }
  return result;
}

