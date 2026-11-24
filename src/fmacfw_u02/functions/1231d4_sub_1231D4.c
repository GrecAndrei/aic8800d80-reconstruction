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

// send_cmd_88 @ 0x1231d4, size 254 bytes
int  send_cmd_88(int a1, uint32_t *a2, uint16_t a3, uint16_t a4)
{
  int v5; // r6
  int v6; // r0
  int v7; // r4
  int v8; // r1
  int result; // r0
  int v10; // r1
  int *v11; // r6
  int v12; // r3
  int v13; // r1
  int *v14; // r5
  char v15; // r0
  int v16; // r1
  int *v17; // r5
  int v18; // r1

  v5 = *a2;
  v6 = ke_msg_alloc(136, a4, a3, 8);
  v7 = v6;
  *(uint32_t *)v6 = v5;
  switch ( v5 )
  {
    case 0:
      v8 = *((uint8_t *)a2 + 4);
      BYTE1(((uint32_t *)(uintptr_t)off_1232D4)[93]) = v8;
      *(uint8_t *)(v6 + 4) = v8;
      event_dispatch("tim_bcmc_ign:%x\n", v8);
      goto LABEL_3;
    case 1:
      v11 = (int *)off_1232D4;
      v12 = *((uint8_t *)a2 + 4);
      v13 = HIBYTE(((uint32_t *)(uintptr_t)off_1232D4)[90]);
      HIBYTE(((uint32_t *)(uintptr_t)off_1232D4)[90]) = v12;
      v11[91] = a2[2];
      if ( v12 != v13 )
      {
        if ( v12 )
        {
          rf_get_channel_calibration();
          rf_enable_2();
        }
        else
        {
          rf_disable();
        }
        v13 = *((uint8_t *)v11 + 363);
      }
      *(uint8_t *)(v7 + 4) = v13;
      event_dispatch("temp_comp_en:%x\n", v13);
      ke_msg_send_2(v7);
      result = 0;
      break;
    case 2:
      v14 = (int *)off_1232D4;
      *(uint8_t *)(v6 + 4) = HIBYTE(((uint32_t *)(uintptr_t)off_1232D4)[90]);
      v15 = rf_get_bandwidth();
      *(uint8_t *)(v7 + 5) = v15;
      event_dispatch("temp_comp_en:%x,t=%d\n", *((uint8_t *)v14 + 363), v15);
      ke_msg_send_2(v7);
      result = 0;
      break;
    case 3:
      v16 = a2[1];
      v17 = (int *)off_1232D4;
      ((uint32_t *)(uintptr_t)off_1232D4)[98] = v16;
      event_dispatch("set ext_flags:0x%x\n", v16);
      *(uint32_t *)(v7 + 4) = v17[98];
      ke_msg_send_2(v7);
      result = 0;
      break;
    case 4:
      v18 = ((uint32_t *)(uintptr_t)off_1232D4)[98];
      *(uint32_t *)(v6 + 4) = v18;
      event_dispatch("get ext_flags:0x%x\n", v18);
      ke_msg_send_2(v7);
      result = 0;
      break;
    case 5:
      v10 = (a2[2] ^ ((uint32_t *)(uintptr_t)off_1232D4)[98]) & a2[1] ^ ((uint32_t *)(uintptr_t)off_1232D4)[98];
      ((uint32_t *)(uintptr_t)off_1232D4)[98] = v10;
      *(uint32_t *)(v6 + 4) = v10;
      event_dispatch("mask set ext_flags:0x%x\n", v10);
      ke_msg_send_2(v7);
      result = 0;
      break;
    default:
LABEL_3:
      ke_msg_send_2(v7);
      result = 0;
      break;
  }
  return result;
}
