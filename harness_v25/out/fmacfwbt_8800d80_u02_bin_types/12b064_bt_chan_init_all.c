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

extern uint32_t dword_12B094;

// bt_chan_init_all @ 0x12b064, size 48 bytes
// Doc: bt_chan_init_all [bt]: Initialize BT channels 0..3 via per-channel setup helper
// bt_chan_init_all [bt]: Initialize BT channels 0..3 via per-channel setup helper
int *bt_chan_init_all()
{
  int *result; // r0
  uint8_t *v1; // r3
  int v2; // r1

  phy_tbl_lookup_by_idx(0);
  phy_tbl_lookup_by_idx(1);
  phy_tbl_lookup_by_idx(2);
  result = phy_tbl_lookup_by_idx(3);
  v1 = (uint8_t *)dword_12B094;
  v2 = dword_12B094 + 96;
  do
  {
    v1[1] = 0;
    v1[2] = 0;
    *v1 = 0;
    v1 += 3;
  }
  while ( v1 != (uint8_t *)v2 );
  return result;
}

