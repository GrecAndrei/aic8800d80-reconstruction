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

extern uint32_t off_123A18;
extern uint32_t off_123A1C;
extern uint32_t dword_123A24;
extern uint32_t dword_123A20;

// check_wlc_state @ 0x1239d4, size 68 bytes
int  check_wlc_state(int a1, uint8_t *a2, int a3, int a4)
{
  int v7; // r0
  int v8; // r3

  if ( **(int16_t **)off_123A18 < 0 )
  {
    v7 = *a2;
    if ( HIBYTE(*(uint32_t *)off_123A1C) + 8 >= v7 )
      goto LABEL_3;
    mmio_irq_clear(dword_123A24, dword_123A20, 1801);
  }
  v7 = *a2;
LABEL_3:
  check_hw_version(v7);
  hci_evt_alloc_send(39, a4, a3, v8);
  return 0;
}

