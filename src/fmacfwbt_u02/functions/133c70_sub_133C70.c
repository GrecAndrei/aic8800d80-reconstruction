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

extern uint32_t off_133CCC;
extern uint32_t dword_133CD4;
extern uint32_t dword_133CD0;

// mmio_init @ 0x133c70, size 90 bytes
int mmio_init()
{
  int v0; // r2
  int v2; // [sp+0h] [bp-Ch] BYREF
  int v3; // [sp+4h] [bp-8h] BYREF

  v0 = **(int16_t **)off_133CCC;
  v2 = 0;
  v3 = 0;
  if ( v0 < 0 && hci_cmd_send_short(6u) != 1 )
    mmio_irq_clear(dword_133CD4, dword_133CD0, 303);
  ull_scan_event_start(&v2, &v3);
  if ( v2 && v3 )
  {
    rx_security_check();
    return 0;
  }
  else
  {
    event_dispatch(1);
    return 0;
  }
}

