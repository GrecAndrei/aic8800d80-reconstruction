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

// rx_validate_frame_type @ 0x13ac0c, size 54 bytes
// Doc: rx_validate_frame_type [rx]: Check ethertype field (0x600) on frame
// rx_validate_frame_type [rx]: Check ethertype field (0x600) on frame
int  rx_validate_frame_type(int a1, uint16_t *a2)
{
  unsigned int v2; // r2
  uint16_t *v4; // r1

  v2 = *(uint16_t *)(a1 + 24);
  if ( (uint16_t)__rev16(v2) >= 0x600u )
  {
    *(a2 - 4) = -21846;
    a2 -= 4;
    a2[3] = v2;
    a2[1] = 3;
    a2[2] = 0;
  }
  v4 = rf_set_channel_table(a1, a2, 1);
  return rf_configure_channel(a1, (int)v4);
}

