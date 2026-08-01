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

// key_install_check @ 0x129b20, size 56 bytes
uint8_t * key_install_check(uint8_t *result)
{
  int v1; // r3
  uint8_t *v2; // r4
  int v3; // r1

  v1 = result[114];
  v2 = result;
  if ( v1 == 1 )
  {
    result[114] = 0;
    return rsn_parse_ie(result);
  }
  else if ( v1 == 2 )
  {
    v3 = *((uint32_t *)result + 29);
    result[114] = 1;
    mem_copy_util((int)(result + 96), v3);
    return rsn_parse_ie(v2);
  }
  return result;
}

