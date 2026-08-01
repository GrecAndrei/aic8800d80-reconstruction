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

extern uint32_t off_141FB4;

// set_conn_flag @ 0x141f70, size 68 bytes
// Doc: sub_1241F70 [unknown]: Unknown behavioral stub
// sub_1241F70 [unknown]: Unknown behavioral stub
int  set_conn_flag(int a1)
{
  int16_t v1; // r3
  uint8_t *v3; // r1
  int result; // r0

  v1 = *(uint16_t *)a1;
  if ( (*(uint16_t *)a1 & 8) != 0 )
  {
    v3 = off_141FB4;
    *(uint16_t *)a1 = v1 | 0x40;
    if ( v3[1] )
    {
      if ( (v1 & 9) == 9 )
        build_tx_packet(a1);
    }
  }
  result = ke_event_set_lock(a1 + 52);
  if ( !*(uint8_t *)(a1 + 4) )
  {
    result = *(uint8_t *)(a1 + 47);
    *((uint8_t *)off_141FB4 + 2) &= ~(1 << result);
  }
  return result;
}

