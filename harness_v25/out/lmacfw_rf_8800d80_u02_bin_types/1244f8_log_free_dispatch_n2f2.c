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

extern uint32_t off_12451C;

// log_free_dispatch_n2f2 @ 0x1244f8, size 36 bytes
// Doc: log_free_dispatch_n2f2 [util]: Dispatches log free with rotated value, likely a logger release
// log_free_dispatch_n2f2 [util]: Dispatches log free with rotated value, likely a logger release
int log_free_dispatch_n2f2()
{
  int result; // r0
  int v1; // r3

  result = rf_table_lookup(2u);
  v1 = (uint16_t)(*(uint16_t *)off_12451C + 1);
  if ( v1 == 10 )
  {
    *(uint16_t *)off_12451C = 0;
    return rf_init_n_dc(result);
  }
  else
  {
    *(uint16_t *)off_12451C = v1;
  }
  return result;
}

