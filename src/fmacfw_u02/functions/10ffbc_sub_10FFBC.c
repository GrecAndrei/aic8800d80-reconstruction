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

extern uint32_t off_10FFFC;
extern uint32_t dword_110000;
extern uint32_t dword_110004;

// is_hci_initialized @ 0x10ffbc, size 62 bytes
uint32_t * is_hci_initialized(char a1)
{
  uint32_t *v2; // r4

  if ( **(uint8_t **)off_10FFFC == 1 )
    v2 = (uint32_t *)is_hold_mode();
  else
    v2 = rx_packet_handler(dword_110000, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( check_controller_mode((unsigned int)v2) )
  {
    *((uint8_t *)v2 - 1) = a1;
    return v2;
  }
  log_printf(dword_110004, v2);
  return v2;
}

