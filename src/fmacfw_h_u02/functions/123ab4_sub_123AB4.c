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

extern uint32_t off_123B38;
extern uint32_t off_123B3C;
extern uint32_t off_123B40;
extern uint32_t dword_123B48;
extern uint32_t dword_123B44;

// classify_command @ 0x123ab4, size 130 bytes
int  classify_command(int a1, uint8_t *a2, int a3, int a4)
{
  int v7; // r2
  uint16_t *v8; // r5
  int result; // r0

  if ( hci_cmd_handler(a3) == 3 || hci_cmd_handler(a3) == 4 )
    return 2;
  v7 = *a2;
  v8 = off_123B38;
  *((uint8_t *)off_123B38 + 31) = v7;
  if ( !v7 )
  {
    if ( hci_cmd_handler(a3) != 2 )
    {
      rf_write_reg();
LABEL_6:
      mac_write_header_word(35, a4, a3);
      return 0;
    }
    return 2;
  }
  result = hci_cmd_handler(a3);
  if ( !result )
  {
    if ( **(int16_t **)off_123B3C < 0 )
    {
      if ( *(uint32_t *)off_123B40 << 28 )
        irq_disable_mmio_write(dword_123B48, dword_123B44, 1522);
    }
    v8[9] = 0;
    goto LABEL_6;
  }
  if ( result != 2 )
  {
    rf_status_check(result);
    hci_cmd_preprocess(a3);
    return 2;
  }
  return result;
}

