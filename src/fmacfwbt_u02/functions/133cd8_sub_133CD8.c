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

extern uint32_t off_133DE4;
extern uint32_t dword_133DFC;
extern uint32_t dword_133DF8;
extern uint32_t off_133DE8;
extern uint32_t off_133DEC;
extern uint32_t dword_133DF0;
extern uint32_t dword_133DF4;

// util_reset @ 0x133cd8, size 266 bytes
// Doc: sub_1233CD8 [unknown]: Unknown helper in fmacfwbt image (reconstructed flow)
// sub_1233CD8 [unknown]: Unknown helper in fmacfwbt image (reconstructed flow)
int util_reset()
{
  int v0; // r2
  unsigned int v1; // r3
  uint8_t *v2; // r3
  uint8_t *v4; // r4
  int v5; // r3
  int v6; // r1
  int v7; // [sp+0h] [bp-Ch] BYREF
  int v8; // [sp+4h] [bp-8h] BYREF

  if ( **(int16_t **)off_133DE4 < 0 && hci_cmd_send_short(6u) != 4 && hci_cmd_send_short(6u) != 10 )
    mmio_irq_clear(dword_133DFC, dword_133DF8, 697);
  if ( hci_cmd_send_short(6u) == 10 )
  {
    v4 = off_133DE8;
    v5 = *((uint8_t *)off_133DE8 + 4);
    *(uint32_t *)(*((uint32_t *)off_133DE8 + 2) + 472) = 0;
    if ( v5 )
    {
      hci_evt_alloc_send(6148, 13, 6);
      v4[4] = 0;
    }
    hci_evt_send(*(uint32_t *)v4 + 12);
    v6 = (uint8_t)v4[33];
    *(uint32_t *)v4 = 0;
    if ( v6 )
    {
      v7 = 0;
      v8 = 0;
      ull_scan_event_start(&v7, &v8);
      rx_security_check(v7, v8, 0);
    }
    else
    {
      hci_cmd_send(6u, 0);
    }
    return 0;
  }
  else
  {
    v0 = *((uint32_t *)off_133DE8 + 4);
    v1 = *(uint8_t *)(v0 + 59);
    if ( v1 == 2 )
    {
      if ( (*(uint32_t *)(v0 + 48) & 0x40) != 0 )
      {
        rf_lookup_alt_by_index();
        v2 = off_133DEC;
        if ( *((uint8_t *)off_133DEC + 13) )
        {
LABEL_6:
          if ( (v2[15] & 1) != 0 )
          {
            patch_aware_dispatch(6155, 6, dword_133DF0);
            clock_disable();
          }
        }
        return 0;
      }
LABEL_5:
      rf_lookup_by_index(1, 0);
      v2 = off_133DEC;
      if ( *((uint8_t *)off_133DEC + 13) )
        goto LABEL_6;
      return 0;
    }
    if ( v1 <= 2 )
      goto LABEL_5;
    if ( v1 == 3 )
    {
      rf_check_status(dword_133DF4);
      if ( *((uint8_t *)off_133DEC + 13) )
        *((uint8_t *)off_133DEC + 15) |= 2u;
      return 0;
    }
    event_dispatch(1);
    return 0;
  }
}

