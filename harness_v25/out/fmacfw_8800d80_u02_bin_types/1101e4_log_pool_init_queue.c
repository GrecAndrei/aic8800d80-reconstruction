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

// log_pool_init_queue @ 0x1101e4, size 52 bytes
// Doc: log_free_dispatch_n1f4 [util]: Free log entry and dispatch next pending log
// log_free_dispatch_n1f4 [util]: Free log entry and dispatch next pending log
int log_pool_init_queue()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = log_free_dispatch_n210_0218;
  result = sub_12D240(log_free_dispatch_n215);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 2) )
  {
    v2 = log_free_dispatch_n218_0;
    v3 = log_free_dispatch_n215;
    v4 = 0;
    do
    {
      sub_10FB28(v2, 0xCu);
      result = list_push_tail(v3);
      ++v4;
    }
    while ( *(uint16_t *)(*(uint32_t *)v0 + 2) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}

