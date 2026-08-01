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

// bt_conn_init @ 0x125d18, size 44 bytes
int  bt_conn_init(int a1, int a2)
{
  uint8_t v3; // r0

  if ( a1 > 1 )
  {
    v3 = parse_number(*(uint8_t **)(a2 + 4), 0, 0xAu);
    ll_state_process(0, 0, v3);
  }
  else
  {
    ll_state_process(0, 0, 0);
  }
  return 0;
}

