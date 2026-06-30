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

extern uint32_t off_110108;

// log_free_dispatch_n274 @ 0x1100d4, size 52 bytes
// Doc: log_free_dispatch_2a6 [util]: Dispatches freed log buffer entries
// log_free_dispatch_2a6 [util]: Dispatches freed log buffer entries
int log_free_dispatch_n274()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = off_110108;
  result = bt_xtal_init_check(log_free_dispatch_n2ac);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 4) )
  {
    v2 = log_free_dispatch_n2b0;
    v3 = log_free_dispatch_n2ac;
    v4 = 0;
    do
    {
      log_pool_alloc2(v2, 0x7Cu);
      result = list_push_tail(v3);
      ++v4;
    }
    while ( *(uint16_t *)(*(uint32_t *)v0 + 4) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}

