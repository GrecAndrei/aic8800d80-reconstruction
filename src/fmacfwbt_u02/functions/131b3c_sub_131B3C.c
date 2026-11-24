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


extern uint32_t off_131B84;
extern uint32_t off_131B88;

// llm_adv_start @ 0x131b3c, size 70 bytes
int  llm_adv_start(int a1, int a2, int a3)
{
  int v4; // r1

  if ( **(uint16_t **)off_131B84 < 0 && hci_cmd_send_short(a3) != 1 )
    mmio_irq_clear((int)aKeStateGetDest_1, (int)aMmSetPsModeCfm, 822);
  v4 = *((uint16_t *)off_131B88 + 4);
  if ( v4 != 255 )
    hci_evt_alloc_send(5146, v4, a3);
  hci_cmd_send(a3, 0);
  return 0;
}
