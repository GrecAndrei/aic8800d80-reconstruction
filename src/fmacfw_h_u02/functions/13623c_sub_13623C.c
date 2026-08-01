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

extern uint32_t off_1362C8;
extern uint32_t dword_1362D8;
extern uint32_t dword_1362D0;
extern uint32_t off_1362CC;
extern uint32_t dword_1362D4;

// is_link_active @ 0x13623c, size 140 bytes
int is_link_active()
{
  int16_t **v0; // r4

  v0 = (int16_t **)off_1362C8;
  if ( **(int16_t **)off_1362C8 < 0 && hci_cmd_handler(7u) != 1 && hci_cmd_handler(7u) && hci_cmd_handler(7u) != 3 )
    irq_disable_mmio_write(dword_1362D8, dword_1362D0, 341);
  if ( hci_cmd_handler(7u) == 1 )
  {
    if ( **v0 < 0 && *((uint32_t *)off_1362CC + 1) )
      irq_disable_mmio_write(dword_1362D4, dword_1362D0, 349);
    send_hci_command();
  }
  else if ( hci_cmd_handler(7u) == 3 )
  {
    mac_write_header_word(7171, 13, 7);
    hci_cmd_preprocess(7u, 0);
  }
  return 0;
}

