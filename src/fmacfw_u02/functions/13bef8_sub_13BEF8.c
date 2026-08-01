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

extern uint32_t dword_13BF60;
extern uint32_t dword_13BF70;
extern uint32_t dword_13BF74;
extern uint32_t dword_13BF64;
extern uint32_t dword_13BF68;
extern uint32_t dword_13BF6C;

// rf_get_chan_param @ 0x13bef8, size 104 bytes
// Doc: sub_123BEF8 [util]: Indexed table lookup/handler dispatch using 32-byte stride entries
// sub_123BEF8 [util]: Indexed table lookup/handler dispatch using 32-byte stride entries
int  rf_get_chan_param(unsigned int a1)
{
  int v1; // r5
  int v2; // r6
  int v3; // r7
  int v5; // r8
  int v6; // r0
  int v7; // r4

  v1 = dword_13BF60;
  v2 = dword_13BF60 + 32 * a1;
  v3 = *(uint8_t *)(v2 + 16);
  v5 = 32 * a1;
  if ( a1 <= 0xF )
  {
    cmd_handler_c(dword_13BF70, (uint32_t *)v2);
    cmd_handler_a(dword_13BF74, (uint32_t *)v2);
  }
  else
  {
    cmd_handler_c(dword_13BF64, (uint32_t *)v2);
    cmd_handler_a(dword_13BF68, (uint32_t *)v2);
  }
  v6 = (a1 << 8) & 0xFF00;
  v7 = dword_13BF6C;
  rx_phy_status_parse(v6 | 8, 4);
  *(uint8_t *)(v1 + v5 + 25) = 0;
  return adv_set_params(v3, v2, 2, 0, 0, 39, v7);
}

