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

extern uint32_t off_103250;
extern uint32_t off_103254;

// get_radio_state @ 0x103200, size 78 bytes
unsigned int  get_radio_state(unsigned int result)
{
  if ( result )
  {
    if ( *((uint8_t *)off_103250 + 362) )
      result = write_phy_config(0xB5u);
    *(uint32_t *)off_103254 |= 2u;
  }
  else
  {
    if ( *((uint8_t *)off_103250 + 362) )
      result = write_phy_config(0xC2u);
    *(uint32_t *)off_103254 &= ~2u;
  }
  return result;
}

