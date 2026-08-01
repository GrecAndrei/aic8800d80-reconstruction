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

extern uint32_t off_12234C;
extern uint32_t off_122344;
extern uint32_t off_122338;
extern uint32_t dword_122354;
extern uint32_t dword_122350;
extern uint32_t off_12233C;
extern uint32_t off_122340;
extern uint32_t dword_122348;

// rf_band_select @ 0x122290, size 168 bytes
// Doc: sub_1222294 [unknown]: Unknown behavioral function in fmacfwbt
// sub_1222294 [unknown]: Unknown behavioral function in fmacfwbt
int  rf_band_select(int a1, int a2)
{
  int v3; // r3
  int v4; // r2
  uint16_t *v5; // r3
  int result; // r0
  uint32_t *v7; // r3
  int v8; // r1
  uint8_t *v9; // r3
  char *v10; // r0

  if ( (a2 & 0x800000) != 0 )
  {
    v7 = off_12234C;
    *(uint8_t *)(a1 + 128) = 0;
    v8 = v7[4];
    v9 = off_122344;
    v10 = (char *)off_122344 + 12;
    *((uint16_t *)off_122344 + 14) = 1793;
    v9[36] = 0;
    *((uint32_t *)v9 + 5) = a1;
    result = ke_event_lock(v10, v8 + 10000);
    *(uint8_t *)(a1 + 115) = 0;
  }
  else
  {
    v3 = (uint8_t)(*(uint8_t *)(a1 + 115) + 1);
    v4 = *(uint32_t *)off_122338;
    *(uint8_t *)(a1 + 115) = v3;
    if ( *(uint8_t *)(v4 + 1) == v3 )
    {
      *(uint8_t *)(a1 + 115) = 0;
      state_check_feature(1024, dword_122354);
      return mmio_read_phy(a1);
    }
    else if ( *(uint8_t *)(a1 + 108) )
    {
      return bt_get_conn_entry(*(uint8_t *)(a1 + 107), dword_122350, a1);
    }
    else
    {
      if ( *((uint8_t *)off_12233C + 2) )
        *(uint32_t *)off_122340 &= ~0x80000000;
      v5 = off_122344;
      if ( *((uint8_t *)off_122344 + 8) )
        --*((uint8_t *)off_122344 + 8);
      v5[14] = 1;
      result = ke_event_set_lock(dword_122348);
      *(uint32_t *)(a1 + 4) &= ~0x200u;
    }
  }
  return result;
}

