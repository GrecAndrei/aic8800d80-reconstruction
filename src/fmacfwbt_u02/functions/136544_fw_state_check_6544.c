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

extern uint32_t off_13657C;
extern uint32_t dword_136584;
extern uint32_t dword_136580;

// txpwr_apply_path @ 0x136544, size 56 bytes
// Doc: txpwr_apply_path [util]: Read global halfword and branch on zero/nonzero
// txpwr_apply_path [util]: Read global halfword and branch on zero/nonzero
int txpwr_apply_path()
{
  if ( **(int16_t **)off_13657C >= 0 || hci_cmd_send_short(7u) == 2 )
  {
    txpwr_send_cmd(0);
    return 0;
  }
  else
  {
    mmio_irq_clear(dword_136584, dword_136580, 388);
    txpwr_send_cmd(0);
    return 0;
  }
}

