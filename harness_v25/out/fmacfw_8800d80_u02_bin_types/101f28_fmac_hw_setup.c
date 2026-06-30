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

extern uint32_t off_101F68;
extern uint32_t off_101F64;

// fmac_hw_setup @ 0x101f28, size 58 bytes
// Doc: fmac_hw_setup [util]: FMAC hardware setup routine
// fmac_hw_setup [util]: FMAC hardware setup routine
int  fmac_hw_setup(int result)
{
  uint32_t *v1; // r2
  unsigned int v2; // r3
  int v3; // r3

  v1 = off_101F68;
  *(uint32_t *)off_101F64 = *(uint32_t *)off_101F64 & 0xFFFFFF | ((uint8_t)(result / 2) << 24);
  v2 = *v1 & 0xFFFFF0FF;
  if ( (result & 1) != 0 )
  {
    if ( result >= 0 )
      v3 = v2 | 0xB00;
    else
      v3 = v2 | 0x500;
    *v1 = v3;
  }
  else
  {
    *v1 = v2 | 0x800;
  }
  return result;
}

