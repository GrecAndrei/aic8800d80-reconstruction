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

extern uint32_t dword_13B634;
extern uint32_t dword_13B630;
extern uint32_t dword_13B62C;

// adv_pdu_conn_req_check @ 0x13b600, size 42 bytes
int  adv_pdu_conn_req_check(int a1, int a2, unsigned int a3)
{
  int v4; // r0

  if ( rx_rate_field_parse(a3) == 1 )
  {
    if ( a3 < 0x1000 )
      v4 = dword_13B634;
    else
      v4 = dword_13B630;
    cmd_handler_a(v4, (uint32_t *)(dword_13B62C + 32 * (a3 >> 8)));
  }
  return 0;
}

