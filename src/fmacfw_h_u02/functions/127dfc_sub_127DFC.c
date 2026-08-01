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

extern uint32_t off_127FD4;
extern uint32_t dword_127FD8;
extern uint32_t dword_127FCC;
extern uint32_t dword_127FD0;

// cfm_dword_get @ 0x127dfc, size 464 bytes
BOOL  cfm_dword_get(int a1, int a2, int a3)
{
  uint8_t *v3; // r11
  int *v4; // r4
  int v8; // r3
  int v9; // r2
  int v10; // r7
  int v11; // r10
  int v12; // r1
  int v13; // r4
  int v15; // r1
  int v16; // r3
  char v17; // r2
  int v18; // r3
  char v19; // r3
  int v20; // r2
  int v21; // [sp+4h] [bp-8h]

  v3 = off_127FD4;
  v4 = *((int **)off_127FD4 + 4);
  if ( v4 )
  {
    v8 = v4[1];
    v9 = *(uint32_t *)(a1 + 72);
    v10 = *((uint32_t *)off_127FD4 + 10);
    v21 = v9;
    if ( v8 == a2 )
    {
LABEL_9:
      v13 = 0;
      if ( (uint8_t)v3[90] > 1u )
        goto LABEL_13;
LABEL_10:
      *(uint8_t *)(a1 + 85) |= 2u;
      ++v3[91];
      return v10 != v21;
    }
    v11 = dword_127FD8;
    while ( v8 - a2 < 0 )
    {
      v12 = *((uint8_t *)v4 + 8);
      if ( v12 == *(uint8_t *)(a1 + 107) )
      {
        alloc_tx_event(v11, v12, v9);
        wlan_ioctl_handler_3(v3 + 16, v4);
        *((uint8_t *)v4 + 9) &= ~1u;
      }
      v4 = (int *)*v4;
      if ( !v4 )
        break;
      v8 = v4[1];
      if ( v8 == a2 )
        goto LABEL_9;
    }
  }
  else
  {
    v10 = *((uint32_t *)off_127FD4 + 10);
    v21 = *(uint32_t *)(a1 + 72);
  }
  v13 = 1;
  if ( (uint8_t)v3[90] <= 1u )
    goto LABEL_10;
LABEL_13:
  if ( *(uint8_t *)(a1 + 86) != 255 )
  {
    llc_env_by_conhdl(a1, a2);
    if ( v13 )
      goto LABEL_31;
    goto LABEL_25;
  }
  if ( !*(uint8_t *)(a1 + 1224) )
  {
    if ( v13 )
    {
      *(uint8_t *)(a1 + 85) |= 4u;
      return v10 != v21;
    }
    goto LABEL_26;
  }
  v15 = dword_127FCC;
  v16 = *(uint8_t *)(a1 + 1225);
  if ( *(uint8_t *)(dword_127FCC + 140 * v16 + 112) != 1 )
  {
    if ( v13 )
    {
      v17 = *(uint8_t *)(a1 + 85);
LABEL_18:
      *(uint8_t *)(a1 + 85) = v17 | 4;
LABEL_19:
      if ( *(uint8_t *)(v15 + 140 * v16 + 112) == 1 )
      {
        v18 = *(uint32_t *)(a1 + 80);
        if ( v18 != a3 && v18 - a3 - 50 < 0 && a3 - v18 - 50 < 0 )
          *(uint32_t *)(a1 + 80) = a3;
      }
      return v10 != v21;
    }
    goto LABEL_26;
  }
  v17 = *(uint8_t *)(a1 + 85);
  if ( (v17 & 0x10) != 0 )
  {
    rf_mode_setup((uint32_t *)a1);
    *(uint8_t *)(a1 + 85) &= ~0x10u;
    if ( v13 )
      goto LABEL_31;
LABEL_25:
    if ( !*(uint8_t *)(a1 + 1224) || *(uint8_t *)(dword_127FCC + 140 * *(uint8_t *)(a1 + 1225) + 112) != 1 )
    {
LABEL_26:
      wlan_ioctl_handler_3(dword_127FD0, a1 + 76);
      v19 = *(uint8_t *)(a1 + 85) & 0xFE;
LABEL_27:
      *(uint8_t *)(a1 + 85) = v19 | 2;
      ++v3[91];
      return v10 != v21;
    }
LABEL_36:
    llc_rx_event_save(a1, a3, 0);
    v19 = *(uint8_t *)(a1 + 85) | 8;
    goto LABEL_27;
  }
  if ( (*(uint8_t *)(a1 + 85) & 0x40) == 0 )
  {
    if ( v13 )
      goto LABEL_18;
    goto LABEL_36;
  }
  llc_obj_release(a1);
  if ( !v13 )
    goto LABEL_25;
LABEL_31:
  v20 = *(uint8_t *)(a1 + 1224);
  *(uint8_t *)(a1 + 85) |= 4u;
  if ( v20 )
  {
    v15 = dword_127FCC;
    v16 = *(uint8_t *)(a1 + 1225);
    goto LABEL_19;
  }
  return v10 != v21;
}

