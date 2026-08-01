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

// rx_channel_event @ 0x11007c, size 72 bytes
// Doc: log_free_pool_dispatch2_n4d0 [util]: Dispatch free pool entry and log release
// log_free_pool_dispatch2_n4d0 [util]: Dispatch free pool entry and log release
int rx_channel_event()
{
  void *v0; // r8
  int result; // r0
  uint32_t *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  unsigned int v6; // r1

  v0 = log_free_pool_dispatch2_n500;
  result = list_init(log_free_pool_dispatch2_00c4);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 6) )
  {
    v2 = log_free_pool_dispatch2_n4f8;
    v3 = log_free_pool_dispatch2_n4fc;
    v4 = log_free_pool_dispatch2_00c4;
    v5 = 0;
    do
    {
      list_iterate(v3, 0x63Cu);
      result = check_kernel_state(v4);
      v6 = *(uint16_t *)(*(uint32_t *)v0 + 6);
      ++v5;
      ++*v2;
    }
    while ( v6 > (uint16_t)v5 );
  }
  return result;
}

