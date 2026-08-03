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

extern uint32_t off_117E5C;
extern uint32_t off_117E60;

// phy_reg_mask_check @ 0x117e34, size 38 bytes
// Doc: phy_reg_mask_check [patch]: Check masked bits of PHY control register 0x40328078
// phy_reg_mask_check [patch]: Check masked bits of PHY control register 0x40328078
int phy_reg_mask_check()
{
  unsigned int v0; // r4
  int result; // r0

  v0 = *(uint32_t *)off_117E5C & 0xF00000;
  if ( v0 )
  {
    result = sub_11B0B4((uint8_t)(11 - __clz(v0)));
    *(uint32_t *)off_117E60 = v0;
  }
  else
  {
    *(uint32_t *)off_117E60 = 0;
  }
  return result;
}

