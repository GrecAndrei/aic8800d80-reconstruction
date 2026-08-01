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

extern uint32_t off_119498;
extern uint32_t off_11949C;
extern uint32_t dword_1194A4;
extern uint32_t dword_1194A0;

// get_hw_pointer @ 0x119448, size 80 bytes
// Doc: fmac_status_check_or_set [mac]: Checks a status bitmask (0x380000) and stores a parameter
// fmac_status_check_or_set [mac]: Checks a status bitmask (0x380000) and stores a parameter
int16_t * get_hw_pointer(int16_t *result)
{
  int v1; // r2
  int v2; // r1
  uint32_t *v3; // r4
  int v4; // r3

  v1 = *((uint32_t *)result + 19);
  if ( *(uint32_t *)(v1 + 28) )
  {
    v2 = *((uint32_t *)off_119498 + 43);
    v3 = result;
    result = *(int16_t **)off_11949C;
    do
    {
      v4 = v3[9] & 0x380000;
      *(uint32_t *)(*(uint32_t *)(v1 + 32) - 3) = v2;
      if ( v4 == 3670016 )
        break;
      v3 = (uint32_t *)*v3;
      if ( *result < 0 && !v3 )
      {
        mmio_clear_register(dword_1194A4, dword_1194A0, 909);
        __und(0xFFu);
      }
      v1 = v3[19];
    }
    while ( *(uint32_t *)(v1 + 28) );
  }
  return result;
}

