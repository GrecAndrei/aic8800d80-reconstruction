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

extern uint32_t off_1232D4;
extern uint32_t dword_1232D8;
extern uint32_t dword_1232E0;
extern uint32_t dword_1232E4;
extern uint32_t dword_1232E8;
extern uint32_t dword_1232EC;
extern uint32_t dword_1232DC;

// send_cmd_88 @ 0x1231d4, size 254 bytes
int  send_cmd_88(int a1, int *a2, int a3, int a4)
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
  int inited; // r0
  uint8_t *v20; // r5
  char v21; // r0
  int v22; // r1
  uint32_t *v23; // r5
  int v24; // r0
  int v25; // r0
  int v26; // r1

  v5 = *a2;
  v6 = ke_msg_alloc(136, a4, a3, 8);
  v8 = v6;
  *(uint32_t *)v6 = v5;
  switch ( v5 )
  {
    case 0:
      v9 = *((uint8_t *)a2 + 4);
      *((uint8_t *)off_1232D4 + 373) = v9;
      v10 = dword_1232D8;
      *(uint8_t *)(v8 + 4) = v9;
      event_dispatch(v10, v9, v7);
      goto LABEL_3;
    case 1:
      v15 = off_1232D4;
      v16 = *((uint8_t *)a2 + 4);
      v17 = *((uint8_t *)off_1232D4 + 363);
      *((uint8_t *)off_1232D4 + 363) = v16;
      v18 = a2[2];
      v15[91] = v18;
      if ( v16 != v17 )
      {
        if ( v16 )
        {
          inited = rf_get_channel_calibration(v6);
          rf_enable(inited);
        }
        else
        {
          rf_disable();
        }
        v17 = *((uint8_t *)v15 + 363);
      }
      *(uint8_t *)(v8 + 4) = v17;
      event_dispatch(dword_1232E0, v17, v18);
      ke_msg_send(v8);
      result = 0;
      break;
    case 2:
      v20 = (uint8_t *)off_1232D4;
      *(uint8_t *)(v6 + 4) = *((uint8_t *)off_1232D4 + 363);
      v21 = rf_get_bandwidth();
      *(uint8_t *)(v8 + 5) = v21;
      event_dispatch(dword_1232E4, v20[363], v21);
      ke_msg_send(v8);
      result = 0;
      break;
    case 3:
      v22 = a2[1];
      v23 = off_1232D4;
      v24 = dword_1232E8;
      *((uint32_t *)off_1232D4 + 98) = v22;
      event_dispatch(v24, v22, v7);
      *(uint32_t *)(v8 + 4) = v23[98];
      ke_msg_send(v8);
      result = 0;
      break;
    case 4:
      v25 = dword_1232EC;
      v26 = *((uint32_t *)off_1232D4 + 98);
      *(uint32_t *)(v8 + 4) = v26;
      event_dispatch(v25, v26, v7);
      ke_msg_send(v8);
      result = 0;
      break;
    case 5:
      v12 = *((uint32_t *)off_1232D4 + 98);
      v13 = dword_1232DC;
      v14 = (a2[2] ^ v12) & a2[1] ^ v12;
      *((uint32_t *)off_1232D4 + 98) = v14;
      *(uint32_t *)(v8 + 4) = v14;
      event_dispatch(v13, v14, v12);
      ke_msg_send(v8);
      result = 0;
      break;
    default:
LABEL_3:
      ke_msg_send(v8);
      result = 0;
      break;
  }
  return result;
}

