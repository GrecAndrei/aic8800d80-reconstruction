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

extern uint32_t dword_141D90;
extern uint32_t off_141D94;
extern uint32_t dword_141D98;

// ll_rx_window_calc @ 0x141d4c, size 66 bytes
// Doc: ll_rx_window_calc [rx]: Compute RX descriptor table entry via multiply by 0x528
// ll_rx_window_calc [rx]: Compute RX descriptor table entry via multiply by 0x528
int  ll_rx_window_calc(int a1, int a2)
{
  int v3; // r5
  int v4; // r0
  int v5; // r2

  v3 = *(uint32_t *)(a1 + 24)
     - 400
     - *(uint32_t *)(a1 + 48) * a2
     - *(uint32_t *)(dword_141D90 + 1320 * *(uint8_t *)(a1 + 47) + 40);
  v4 = util_unknown();
  v5 = *((uint32_t *)off_141D94 + 4);
  *(uint32_t *)(a1 + 56) = dword_141D98;
  return unknown_worker(a1 + 52, v5 + v3 - v4);
}

