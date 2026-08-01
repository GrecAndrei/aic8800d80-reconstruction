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

extern uint32_t off_131BDC;
extern uint32_t dword_131BE8;
extern uint32_t dword_131BE4;
extern uint32_t off_131BE0;

// llm_scan_start @ 0x131b94, size 70 bytes
// Doc: sub_1231B9E [unknown]: Helper routine preserving r4, saving r2 to r4
// sub_1231B9E [unknown]: Helper routine preserving r4, saving r2 to r4
int  llm_scan_start(int a1, int a2, unsigned int a3)
{
  int v4; // r1

  if ( **(int16_t **)off_131BDC < 0 && hci_cmd_send_short(a3) != 1 )
    mmio_irq_clear(dword_131BE8, dword_131BE4, 670);
  v4 = *((uint16_t *)off_131BE0 + 4);
  if ( v4 != 255 )
    hci_evt_alloc_send(5144, v4, a3);
  hci_cmd_send(a3, 0);
  return 0;
}

