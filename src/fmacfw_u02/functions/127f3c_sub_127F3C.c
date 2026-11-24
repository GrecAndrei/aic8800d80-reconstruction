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


extern uint32_t dword_12810C;
extern uint32_t dword_128110;
extern uint32_t off_128114;

// rx_dispatch_frame @ 0x127f3c, size 464 bytes
BOOL  rx_dispatch_frame(int a1, int a2, int a3)
{
  uint8_t *v3; // r11
  int *v4; // r4
  int v8; // r3
  int v9; // r7
  int v10; // r1
  int v11; // r4
  int v13; // r1
  int v14; // r3
  char v15; // r2
  int v16; // r3
  char v17; // r3
  int v18; // r2
  int v19; // [sp+4h] [bp-8h]

  v3 = off_128114;
  v4 = *((int **)off_128114 + 4);
  if ( v4 )
  {
    v8 = v4[1];
    v9 = *((uint32_t *)off_128114 + 10);
    v19 = *(uint32_t *)(a1 + 72);
    if ( v8 == a2 )
    {
LABEL_8:
      v11 = 0;
      if ( (uint8_t)v3[90] > 1u )
        goto LABEL_12;
LABEL_9:
      *(uint8_t *)(a1 + 85) |= 2u;
      ++v3[91];
      return v9 != v19;
    }
    while ( v8 - a2 < 0 )
    {
      v10 = *((uint8_t *)v4 + 8);
      if ( v10 == *(uint8_t *)(a1 + 107) )
      {
        event_dispatch("actually remove:%d\n", v10);
        cmd_handler_c((int)(v3 + 16), v4);
        *((uint8_t *)v4 + 9) &= ~1u;
      }
      v4 = (int *)*v4;
      if ( !v4 )
        break;
      v8 = v4[1];
      if ( v8 == a2 )
        goto LABEL_8;
    }
  }
  else
  {
    v9 = *((uint32_t *)off_128114 + 10);
    v19 = *(uint32_t *)(a1 + 72);
  }
  v11 = 1;
  if ( (uint8_t)v3[90] <= 1u )
    goto LABEL_9;
LABEL_12:
  if ( *(uint8_t *)(a1 + 86) != 255 )
  {
    sta_get_flags(a1, a2);
    if ( v11 )
      goto LABEL_30;
    goto LABEL_24;
  }
  if ( !*(uint8_t *)(a1 + 1224) )
  {
    if ( v11 )
    {
      *(uint8_t *)(a1 + 85) |= 4u;
      return v9 != v19;
    }
    goto LABEL_25;
  }
  v13 = dword_12810C;
  v14 = *(uint8_t *)(a1 + 1225);
  if ( *(uint8_t *)(dword_12810C + 140 * v14 + 112) != 1 )
  {
    if ( v11 )
    {
      v15 = *(uint8_t *)(a1 + 85);
LABEL_17:
      *(uint8_t *)(a1 + 85) = v15 | 4;
LABEL_18:
      if ( *(uint8_t *)(v13 + 140 * v14 + 112) == 1 )
      {
        v16 = *(uint32_t *)(a1 + 80);
        if ( v16 != a3 && v16 - a3 - 50 < 0 && a3 - v16 - 50 < 0 )
          *(uint32_t *)(a1 + 80) = a3;
      }
      return v9 != v19;
    }
    goto LABEL_25;
  }
  v15 = *(uint8_t *)(a1 + 85);
  if ( (v15 & 0x10) != 0 )
  {
    lld_evt_schedule((uint32_t *)a1);
    *(uint8_t *)(a1 + 85) &= ~0x10u;
    if ( v11 )
      goto LABEL_30;
LABEL_24:
    if ( !*(uint8_t *)(a1 + 1224) || *(uint8_t *)(dword_12810C + 140 * *(uint8_t *)(a1 + 1225) + 112) != 1 )
    {
LABEL_25:
      cmd_handler_c(dword_128110, (uint32_t *)(a1 + 76));
      v17 = *(uint8_t *)(a1 + 85) & 0xFE;
LABEL_26:
      *(uint8_t *)(a1 + 85) = v17 | 2;
      ++v3[91];
      return v9 != v19;
    }
LABEL_35:
    llm_scan_sm_execute(a1, a3, 0);
    v17 = *(uint8_t *)(a1 + 85) | 8;
    goto LABEL_26;
  }
  if ( (*(uint8_t *)(a1 + 85) & 0x40) == 0 )
  {
    if ( v11 )
      goto LABEL_17;
    goto LABEL_35;
  }
  ke_process_event(a1, dword_12810C);
  if ( !v11 )
    goto LABEL_24;
LABEL_30:
  v18 = *(uint8_t *)(a1 + 1224);
  *(uint8_t *)(a1 + 85) |= 4u;
  if ( v18 )
  {
    v13 = dword_12810C;
    v14 = *(uint8_t *)(a1 + 1225);
    goto LABEL_18;
  }
  return v9 != v19;
}
