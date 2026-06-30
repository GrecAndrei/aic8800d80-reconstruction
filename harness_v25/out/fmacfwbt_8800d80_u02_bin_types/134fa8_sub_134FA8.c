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

extern uint32_t off_135000;
extern uint32_t dword_135008;
extern uint32_t dword_135004;

// sub_134FA8 @ 0x134fa8, size 86 bytes
// Doc: sub_1234FA8 [ipc]: Build and post a 6/0xa-typed message with 3 payload words
// sub_1234FA8 [ipc]: Build and post a 6/0xa-typed message with 3 payload words
int  sub_134FA8(int a1, int a2, int a3)
{
  uint32_t *v3; // r5

  v3 = off_135000;
  *((uint8_t *)off_135000 + 4) = a3;
  v3[2] = a1;
  *((uint16_t *)v3 + 6) = a2;
  rf_bus_mark_n_3b7(6u, 10);
  feature_guard_sdio(
    256,
    dword_135008,
    *(uint8_t *)(a1 + 107),
    a2,
    *(uint16_t *)(dword_135004 + 696 * *(uint8_t *)(a1 + 116) + 50),
    a3);
  if ( *((uint8_t *)v3 + 4) )
    return bt_state_poll_n_cac();
  else
    return sub_134B30();
}

