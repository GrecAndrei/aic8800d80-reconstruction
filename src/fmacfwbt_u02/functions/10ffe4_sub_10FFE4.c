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

// rx_irq_handler @ 0x10ffe4, size 72 bytes
// Doc: log_free_dispatch_n1bc [util]: Frees log entry and dispatches next log buffer
// log_free_dispatch_n1bc [util]: Frees log entry and dispatches next log buffer
int rx_irq_handler()
{
  void *v0; // r8
  int result; // r0
  uint32_t *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  unsigned int v6; // r1

  v0 = log_free_dispatch_n1d8;
  result = zero_struct(log_free_dispatch_n1cc);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 6) )
  {
    v2 = patch_apply_n_32;
    v3 = log_free_dispatch_n1d4;
    v4 = log_free_dispatch_n1cc;
    v5 = 0;
    do
    {
      rx_process_item(v3, 0x63Cu);
      result = check_abort_flag(v4);
      v6 = *(uint16_t *)(*(uint32_t *)v0 + 6);
      ++v5;
      ++*v2;
    }
    while ( v6 > (uint16_t)v5 );
  }
  return result;
}

