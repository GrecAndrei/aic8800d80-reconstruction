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

extern uint32_t off_121418;

// check_isr_handler @ 0x1213ec, size 42 bytes
// Doc: check_isr_handler [rf]: RF bus write operation
// check_isr_handler [rf]: RF bus write operation
int check_isr_handler()
{
  if ( hci_cmd_send_short(0) == 1 )
    *(uint32_t *)off_121418 = 48;
  return hci_cmd_send(0);
}

