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

// sub_11BA4C @ 0x11ba4c, size 22 bytes
int  sub_11BA4C(int a1, int a2, int a3)
{
  int result; // r0

  rf_link_state_check(a1, a2, a3);
  result = sub_11B740();
  if ( !result )
    return sub_11B9E0();
  return result;
}

