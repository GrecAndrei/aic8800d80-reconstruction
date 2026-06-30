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

extern uint32_t off_137224;

// bt_cmd_dispatch_setup @ 0x1371d0, size 82 bytes
// Doc: bt_cmd_dispatch_setup [bt]: Initializes BT command slots/queue at f08/f0a offsets
// bt_cmd_dispatch_setup [bt]: Initializes BT command slots/queue at f08/f0a offsets
int  bt_cmd_dispatch_setup(int a1, int a2, int a3, int a4)
{
  uint16_t *v4; // r2
  uint64_t v6; // r0
  uint8_t *v8; // r0
  int v9; // r0

  v4 = off_137224;
  *((uint16_t *)off_137224 + 1924) = a4;
  v4[1925] = 0;
  v6 = *(uint64_t *)(a2 + 352);
  *(uint32_t *)v4 = a2;
  *((uint32_t *)v4 + 963) = v6;
  v4[1928] = WORD2(v6);
  if ( a4 == 11 || a4 == 6 )
  {
    sub_13876C(v6);
    return 1;
  }
  else
  {
    v8 = (uint8_t *)rf_bus_setup_n3a8(4105, a4, 4, 2u);
    v8[1] = 1;
    *v8 = *(uint8_t *)(a2 + 366);
    v9 = sub_12CBB4((int)v8);
    sub_13876C(v9);
    return 1;
  }
}

