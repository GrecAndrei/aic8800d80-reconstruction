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

extern uint32_t dword_1369B0;
extern uint32_t off_1369B4;
extern uint32_t dword_1369BC;
extern uint32_t dword_1369B8;

// txpwr_get_state @ 0x13697c, size 50 bytes
int txpwr_get_state()
{
  uint32_t *v0; // r0
  uint32_t *v1; // r4

  v0 = list_pop_front(dword_1369B0);
  v1 = v0;
  if ( **(int16_t **)off_1369B4 < 0 && !v0 )
    mmio_irq_clear(dword_1369BC, dword_1369B8, 210);
  return hci_evt_send((int)(v1 + 3));
}

