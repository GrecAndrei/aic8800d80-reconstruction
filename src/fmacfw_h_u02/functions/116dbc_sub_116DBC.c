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

// phy_lock @ 0x116dbc, size 52 bytes
BOOL  phy_lock(int a1)
{
  if ( *((uint8_t *)off_116DF0 + 510) )
    return 0;
  if ( !cfm_call_ops() )
    return 0;
  if ( *(uint8_t *)(a1 + 1224) )
    return bt_get_conn_channel(*(uint8_t *)(a1 + 1225)) != 0;
  return 1;
}

