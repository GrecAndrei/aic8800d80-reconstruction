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

extern uint32_t off_134CA4;
extern uint32_t dword_134CAC;
extern uint32_t dword_134CA8;

// ke_timer_set @ 0x134c4c, size 86 bytes
int  ke_timer_set(int a1, int a2, int a3)
{
  uint32_t *v3; // r5

  v3 = off_134CA4;
  *((uint8_t *)off_134CA4 + 4) = a3;
  v3[2] = a1;
  *((uint16_t *)v3 + 6) = a2;
  hci_cmd_preprocess(6u, 10);
  check_feature_flag(
    256,
    dword_134CAC,
    *(uint8_t *)(a1 + 107),
    a2,
    *(uint16_t *)(dword_134CA8 + 696 * *(uint8_t *)(a1 + 116) + 50),
    a3);
  if ( *((uint8_t *)v3 + 4) )
    return ble_rx_process();
  else
    return ble_load_defaults();
}

