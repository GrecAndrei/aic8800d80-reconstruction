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

// message_dispatch_c7ac @ 0x12c7ac, size 44 bytes
// Doc: message_dispatch_n_3fc [ipc]: Message dispatch comparator clamping against 0x7f boundary
// message_dispatch_n_3fc [ipc]: Message dispatch comparator clamping against 0x7f boundary
int  message_dispatch_c7ac(int result)
{
  int *i; // r3
  int v2; // r2
  int v3; // r3

  v2 = *(char *)(result + 110);
  v3 = (char)(*(uint8_t *)(result + 420) - *(uint8_t *)(result + 464));
  if ( v2 == 127 )
  {
    *(uint8_t *)(result + 109) = 127;
    if ( v3 == 127 )
      return result;
  }
  else if ( v3 >= v2 )
  {
    LOBYTE(v3) = *(uint8_t *)(result + 110);
  }
  *(uint8_t *)(result + 109) = v3;
  for ( i = *(int **)(result + 240); i; i = (int *)*i )
    *((uint8_t *)i + 350) |= 0x10u;
  result = *(uint32_t *)(result + 72);
  if ( result )
    return sub_12876C(result);
  return result;
}

