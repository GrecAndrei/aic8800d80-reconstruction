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

extern uint32_t off_131828;
extern uint32_t dword_131834;
extern uint32_t dword_131830;
extern uint32_t off_13182C;

// is_link_connected @ 0x1317e0, size 70 bytes
int  is_link_connected(int a1, int a2, unsigned int a3)
{
  int v4; // r1

  if ( **(int16_t **)off_131828 < 0 && hci_cmd_handler(a3) != 1 )
    irq_disable_mmio_write(dword_131834, dword_131830, 822);
  v4 = *((uint16_t *)off_13182C + 4);
  if ( v4 != 255 )
    mac_write_header_word(5146, v4, a3);
  hci_cmd_preprocess(a3, 0);
  return 0;
}

