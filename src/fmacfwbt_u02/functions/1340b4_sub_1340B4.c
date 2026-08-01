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

extern uint32_t dword_134274;
extern uint32_t off_134278;
extern uint32_t dword_13426C;
extern uint32_t dword_134268;
extern uint32_t dword_134270;
extern uint32_t off_13427C;
extern uint32_t dword_134264;
extern uint32_t off_134258;
extern uint32_t off_13425C;
extern uint32_t off_134254;
extern uint32_t dword_134260;

// llm_state_check_ready @ 0x1340b4, size 416 bytes
int  llm_state_check_ready(int a1, int a2, int16_t a3, int16_t a4)
{
  int v4; // r9
  uint8_t *v8; // r5
  int v9; // r8
  uint8_t *v10; // r3
  int16_t **v11; // r10
  uint32_t *v12; // r9
  int *v13; // r1
  uint8_t *v14; // r2
  int v15; // r3
  int v16; // r3
  int v17; // r0
  int v18; // r6
  int v19; // r4
  int v21; // r1
  int v22; // r0
  int v23; // [sp+0h] [bp-8h] BYREF
  int v24; // [sp+4h] [bp-4h] BYREF

  v4 = *(uint8_t *)(a2 + 61);
  if ( hci_cmd_send_short(6u) != 10 )
  {
    v8 = (uint8_t *)bt_buf_alloc(6145, a4, a3, 1u);
    if ( hci_cmd_send_short(6u) )
    {
      *v8 = 8;
      v19 = 0;
    }
    else if ( *(uint8_t *)(a2 + 61) > 3u
           || (v9 = dword_134274, v10 = (uint8_t *)(dword_134274 + 1320 * v4), v10[106]) )
    {
      *v8 = 4;
      v19 = 0;
    }
    else
    {
      if ( !v10[108] )
      {
        v11 = (int16_t **)off_134278;
        if ( **(int16_t **)off_134278 < 0 )
        {
          if ( (uint8_t)v10[116] == 255 || (mmio_irq_clear(dword_13426C, dword_134268, 102), **v11 < 0) )
          {
            if ( *(uint32_t *)(v9 + 1320 * v4 + 72) )
              mmio_irq_clear(dword_134270, dword_134268, 103);
          }
        }
        v12 = off_13427C;
        *((uint8_t *)off_13427C + 33) = 0;
        goto LABEL_8;
      }
      v21 = *(uint32_t *)(a2 + 48) & 0x20;
      if ( v21 )
      {
        v12 = off_13427C;
        v22 = dword_134264;
        *((uint8_t *)off_13427C + 33) = 1;
        ke_event_schedule(v22, v21);
LABEL_8:
        v13 = (int *)off_134258;
        v14 = off_13425C;
        *(uint8_t *)off_134254 = 0;
        v15 = *v13;
        v14[32] = 0;
        *v13 = v15 | 0x10;
        v16 = *(uint8_t *)(a2 + 59);
        v14[14] = 1;
        if ( v16 == 3 && hci_event_parse(a2 + 64, *(uint16_t *)(a2 + 54)) > 0 )
          *(uint8_t *)(a2 + 59) = 0;
        v12[4] = a2;
        v17 = bt_buf_alloc(6146, a4, a3, 0x354u);
        v18 = *((uint8_t *)v12 + 33);
        v12[5] = v17;
        if ( v18 )
        {
          memcpy_aligned(dword_134260, v9 + 1320 * *(uint8_t *)(a2 + 61) + 64, 6);
          init_rf_config(v9 + 1320 * *(uint8_t *)(a2 + 61), 0, 0);
        }
        else
        {
          v23 = 0;
          v24 = 0;
          ull_scan_event_start(&v23, &v24);
          if ( v23 && v24 )
            rx_security_check(v23, v24, 0);
          else
            wlan_hw_init();
        }
        *v8 = 0;
        v19 = 1;
        goto LABEL_13;
      }
      v19 = 0;
      *v8 = 9;
    }
LABEL_13:
    hci_evt_send((int)v8);
    return v19;
  }
  return 2;
}

