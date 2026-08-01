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

extern uint32_t off_125BEC;
extern uint32_t off_125BF0;
extern uint32_t off_125BE8;
extern uint32_t dword_125BFC;
extern uint32_t dword_125BF8;
extern uint32_t off_125BF4;
extern uint32_t off_125C00;

// rf_status_poll @ 0x125ae4, size 258 bytes
// Doc: rf_status_poll [rf]: RF message body variant with ldrb dispatch table load
// rf_status_poll [rf]: RF message body variant with ldrb dispatch table load
void rf_status_poll()
{
  int v0; // r4
  uint8_t *v1; // r6
  int v2; // r5
  uint32_t *v3; // r2
  int v4; // r7
  uint8_t *v5; // r8
  char v6; // r9
  int v7; // r10
  int v8; // r0
  int v9; // r3

  v0 = *((uint32_t *)off_125BEC + 2);
  v1 = off_125BF0;
  if ( **(int16_t **)off_125BE8 < 0 && *((uint32_t *)off_125BF0 + 1) )
  {
    mmio_irq_clear(dword_125BFC, dword_125BF8, 1074);
    v2 = (uint8_t)v1[9];
    if ( v1[9] )
      goto LABEL_20;
  }
  else
  {
    v2 = *((uint8_t *)off_125BF0 + 9);
    if ( *((uint8_t *)off_125BF0 + 9) )
    {
LABEL_20:
      v1[8] = 1;
      return;
    }
  }
  v3 = off_125BF4;
  v1[8] = v2;
  v4 = 32 * *v3;
  if ( v0 )
  {
    v5 = off_125C00;
    v6 = v2;
    v7 = 1;
    while ( 1 )
    {
      if ( *(uint8_t *)(v0 + 106) != 2
        || !*(uint8_t *)(v0 + 226)
        || !*(uint8_t *)(v0 + 108)
        || *(uint8_t *)(v0 + 225) != *(uint8_t *)(v0 + 224) )
      {
        goto LABEL_6;
      }
      if ( tx_complete_handle(v0) )
        ++*v5;
      if ( v7 && (unsigned int)(v4 - 50) > 0xBB6 )
      {
        bt_link_active(v0);
LABEL_16:
        *v5 = v6;
        v0 = *(uint32_t *)v0;
        v7 = 0;
        v2 = 1;
        if ( !v0 )
          return;
      }
      else
      {
        if ( v2 )
          goto LABEL_16;
        v7 = bt_link_active(v0);
        if ( v7 )
        {
          *(uint8_t *)(v0 + 144) = *(uint8_t *)(v0 + 107);
          *(uint8_t *)(v0 + 145) = -1;
          v8 = ble_event_dispatch(v0 + 116, 4);
          v9 = *((uint32_t *)v1 + 1);
          if ( v8 )
            *((uint32_t *)v1 + 1) = ++v9;
          if ( v9 == 1 )
            mac_util_event();
          v7 = 0;
        }
        else
        {
          *v5 = 0;
        }
LABEL_6:
        v0 = *(uint32_t *)v0;
        if ( !v0 )
          return;
      }
    }
  }
}

