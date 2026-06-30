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

extern uint32_t off_116DF0;

// sub_116DBC @ 0x116dbc, size 52 bytes
BOOL  sub_116DBC(int a1)
{
  if ( *((uint8_t *)off_116DF0 + 510) )
    return 0;
  if ( !sub_1283E0() )
    return 0;
  if ( *(uint8_t *)(a1 + 1224) )
    return sub_129FEC(*(uint8_t *)(a1 + 1225)) != 0;
  return 1;
}

