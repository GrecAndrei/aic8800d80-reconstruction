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

extern uint32_t off_121D2C;
extern uint32_t dword_121D40;
extern uint32_t dword_121D3C;
extern uint32_t off_121D30;
extern uint32_t off_121D34;
extern uint32_t off_121D38;

// mac_wait_fw_ready @ 0x121cd4, size 86 bytes
int mac_wait_fw_ready()
{
  if ( **(int16_t **)off_121D2C < 0 && hci_cmd_send_short(0) != 3 )
    mmio_irq_clear(dword_121D40, dword_121D3C, 1785);
  if ( *((uint8_t *)off_121D30 + 31) && *((uint8_t *)off_121D34 + 18) + *((uint8_t *)off_121D34 + 17) <= 1 )
    return hci_cmd_send(0);
  *(uint32_t *)off_121D38 = 48;
  return hci_cmd_send(0);
}

