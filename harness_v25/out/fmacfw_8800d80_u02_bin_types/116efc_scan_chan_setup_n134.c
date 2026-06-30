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

extern uint32_t off_116F30;

// scan_chan_setup_n134 @ 0x116efc, size 52 bytes
// Doc: lmac_handler_xyz [util]: Wrapper that invokes lmac sub-routine at 0x128520
// lmac_handler_xyz [util]: Wrapper that invokes lmac sub-routine at 0x128520
BOOL  scan_chan_setup_n134(int a1)
{
  if ( *((uint8_t *)off_116F30 + 510) )
    return 0;
  if ( !sub_128520() )
    return 0;
  if ( *(uint8_t *)(a1 + 1224) )
    return sub_12A12C(*(uint8_t *)(a1 + 1225)) != 0;
  return 1;
}

