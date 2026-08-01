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

// rf_set_temperature @ 0x11da5c, size 26 bytes
int  rf_set_temperature(int result, int a2)
{
  int v2; // r3

  if ( a2 != 127 )
  {
    v2 = *(char *)(result + 97);
    *(uint8_t *)(result + 97) = a2;
    if ( v2 != a2 )
    {
      result = *(uint32_t *)(result + 72);
      if ( result )
        return bt_conn_find_by_ptr(result);
    }
  }
  return result;
}

