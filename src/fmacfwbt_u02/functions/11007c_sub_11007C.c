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

// adv_irq_handler @ 0x11007c, size 72 bytes
// Doc: log_free_dispatch_n234 [util]: Dispatch and free log buffer entries
// log_free_dispatch_n234 [util]: Dispatch and free log buffer entries
int adv_irq_handler()
{
  void *v0; // r8
  int result; // r0
  uint32_t *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  unsigned int v6; // r1

  v0 = log_free_dispatch_n270;
  result = zero_struct(log_free_dispatch_n264);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 8) )
  {
    v2 = log_free_dispatch_n268;
    v3 = log_free_dispatch_4;
    v4 = log_free_dispatch_n264;
    v5 = 0;
    do
    {
      rx_process_item(v3, 0x6B8u);
      result = check_abort_flag(v4);
      v6 = *(uint16_t *)(*(uint32_t *)v0 + 8);
      ++v5;
      ++*v2;
    }
    while ( v6 > (uint16_t)v5 );
  }
  return result;
}

