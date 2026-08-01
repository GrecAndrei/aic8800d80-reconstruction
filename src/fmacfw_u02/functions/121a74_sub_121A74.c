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

extern uint32_t off_121ACC;
extern uint32_t dword_121AE0;
extern uint32_t dword_121ADC;
extern uint32_t off_121AD0;
extern uint32_t off_121AD4;
extern uint32_t off_121AD8;

// get_shared_s16 @ 0x121a74, size 86 bytes
int get_shared_s16()
{
  if ( **(int16_t **)off_121ACC < 0 && rx_rate_field_parse(0) != 3 )
    mmio_clear_register(dword_121AE0, dword_121ADC, 1785);
  if ( *((uint8_t *)off_121AD0 + 31) && *((uint8_t *)off_121AD4 + 18) + *((uint8_t *)off_121AD4 + 17) <= 1 )
    return rx_phy_status_parse(0);
  *(uint32_t *)off_121AD8 = 48;
  return rx_phy_status_parse(0);
}

