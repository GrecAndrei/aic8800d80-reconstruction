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

// tx_rate_set @ 0x122268, size 36 bytes
int  tx_rate_set(int result, int a2, int a3)
{
  int v3; // r4

  v3 = result;
  if ( (a2 & 0x800000) != 0 )
  {
    *(uint8_t *)(result + 128) = 0;
  }
  else
  {
    state_check_feature(1024, aBcnLinkloss, a3, a2 << 8);
    return (int)mmio_read_phy(v3);
  }
  return result;
}
