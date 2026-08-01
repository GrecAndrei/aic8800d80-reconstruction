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

extern uint32_t dword_134244;
extern uint32_t off_134248;

// hci_send_test_command @ 0x134228, size 26 bytes
int hci_send_test_command()
{
  int result; // r0

  alloc_tx_event(dword_134244);
  result = invalid_handler_12c5fc(6155, 6);
  *((uint8_t *)off_134248 + 15) = 0;
  return result;
}

