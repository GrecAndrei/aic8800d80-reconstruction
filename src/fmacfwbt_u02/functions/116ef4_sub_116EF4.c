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

extern uint32_t off_117074;
extern uint32_t dword_117078;
extern uint32_t off_11707C;
extern uint32_t dword_117088;
extern uint32_t dword_117080;
extern uint32_t dword_117084;

// mac_set_flag @ 0x116ef4, size 384 bytes
int  mac_set_flag(int a1, int a2, int a3, int a4)
{
  int v5; // r6
  int result; // r0
  int v9; // r8
  int v10; // r6
  int v11; // r3
  int v12; // r3
  char v13; // r2
  char v14; // r2
  int16_t v15; // r3
  int16_t v16; // r2
  int16_t v17; // r1
  char v18; // r3
  char v19; // r3
  char v20; // r3
  uint8_t v21[8]; // [sp+0h] [bp-8h] BYREF

  v5 = *(uint16_t *)(a2 + 4);
  result = *(uint16_t *)(a1 + 82) | 4;
  *(uint16_t *)(a1 + 82) = result;
  if ( !v5 )
    goto LABEL_4;
  if ( (*(uint32_t *)(a2 + 36) & 0x200000) == 0 )
  {
    v9 = *(uint32_t *)(a2 + 76);
    if ( **(int16_t **)off_117074 >= 0 )
    {
      v10 = *(uint32_t *)(v9 + 28);
      if ( v10 )
      {
LABEL_11:
        if ( a4 == 4 )
        {
          v12 = dword_117078 + 1320 * *(uint8_t *)(a2 + 28);
          v13 = *(uint8_t *)(v12 + 230);
          if ( (*(uint16_t *)v10 & 0x2000) != 0 )
            v14 = v13 | 2;
          else
            v14 = v13 & 0xFD;
          *(uint8_t *)(v12 + 230) = v14;
        }
        if ( *(uint8_t *)(a2 + 27) == 255 )
        {
          v15 = *(uint8_t *)(v10 + 22) & 0xF;
          if ( (*(uint8_t *)(v10 + 22) & 0xF) != 0 )
          {
            v16 = *((uint16_t *)off_11707C + 254);
          }
          else
          {
            v16 = *((uint16_t *)off_11707C + 254) + 1;
            *((uint16_t *)off_11707C + 254) = v16;
          }
          v17 = *(uint16_t *)(a2 + 30);
          *(uint16_t *)(v10 + 22) = v15 | (16 * v16);
          if ( (v17 & 8) != 0 )
          {
            if ( (*(uint16_t *)v10 & 0xDC) == 0x10 && !*(uint16_t *)(v10 + 26) )
            {
              *(uint16_t *)(a2 + 30) = v17 | 0x20;
              v18 = *(uint8_t *)(v10 + 5);
              v21[0] = *(uint8_t *)(v10 + 4);
              v21[1] = v18;
              v19 = *(uint8_t *)(v10 + 7);
              v21[2] = *(uint8_t *)(v10 + 6);
              v21[3] = v19;
              v20 = *(uint8_t *)(v10 + 9);
              v21[4] = *(uint8_t *)(v10 + 8);
              v21[5] = v20;
              rf_save_cal_values(v21);
              v17 = *(uint16_t *)(a2 + 30);
            }
            if ( (v17 & 0x80) != 0 )
            {
              if ( *(uint8_t *)(a2 + 51) )
              {
                mac_rx_process_ack(a2, v10, 24);
              }
              else if ( *(uint8_t *)(a2 + 53) )
              {
                bt_check_conn_active(a2, v10, *(uint16_t *)(a2 + 4));
              }
            }
          }
        }
        goto LABEL_3;
      }
      goto LABEL_9;
    }
    if ( *(uint32_t *)(a2 + 72) )
    {
      v10 = *(uint32_t *)(v9 + 28);
      if ( v10 )
        goto LABEL_11;
    }
    else
    {
      mmio_irq_clear(dword_117088, dword_117080, 518);
      v10 = *(uint32_t *)(v9 + 28);
      if ( v10 )
        goto LABEL_11;
      if ( **(int16_t **)off_117074 >= 0 )
        goto LABEL_9;
    }
    v11 = *(uint32_t *)(v9 + 24);
    if ( v11 )
      goto LABEL_10;
    mmio_irq_clear(dword_117084, dword_117080, 525);
LABEL_9:
    v11 = *(uint32_t *)(v9 + 24);
LABEL_10:
    v10 = *(uint32_t *)(v11 + 8);
    goto LABEL_11;
  }
LABEL_3:
  result = process_rx_status(a2, a4);
LABEL_4:
  if ( (*(uint32_t *)(a1 + 36) & 0x200000) == 0 )
    return get_bt_param(*(uint32_t *)(a1 + 76) + 12, *(uint32_t *)(a1 + 76) + 12, a4);
  *(uint16_t *)(*(uint32_t *)(a1 + 68) + 8) |= 2u;
  return result;
}

