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

// log_free_dispatch_n1dc @ 0x11003c, size 52 bytes
// Doc: log_free_dispatch_n20a [util]: Dispatch log buffer free handler with priority threshold
// log_free_dispatch_n20a [util]: Dispatch log buffer free handler with priority threshold
int log_free_dispatch_n1dc()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = log_free_dispatch_n210;
  result = bt_xtal_init_check(rf_bus_reset2_n3a9);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 2) )
  {
    v2 = rf_bus_mark_n_458;
    v3 = rf_bus_reset2_n3a9;
    v4 = 0;
    do
    {
      log_pool_alloc2(v2, 0xCu);
      result = list_push_tail(v3);
      ++v4;
    }
    while ( *(uint16_t *)(*(uint32_t *)v0 + 2) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}

