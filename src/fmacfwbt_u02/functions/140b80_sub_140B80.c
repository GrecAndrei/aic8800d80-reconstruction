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

extern uint32_t dword_140C04;
extern uint32_t dword_140C08;
extern uint32_t off_140C10;
extern uint32_t dword_140C0C;

// check_scan_enable @ 0x140b80, size 130 bytes
int  check_scan_enable(int result, int a2)
{
  int v2; // r6
  unsigned int v3; // r4
  int v4; // r7
  int v5; // r3
  int v7; // r0
  int v8; // r4

  v2 = dword_140C04;
  v3 = *(uint8_t *)(dword_140C04 + 6489);
  if ( v3 <= 3 && *(uint8_t *)(dword_140C04 + 6488) <= 0x1Fu )
  {
    v4 = result;
    v5 = *(uint32_t *)(dword_140C08 + 1320 * v3 + 72);
    v7 = v5 ? *(uint8_t *)(v5 + 4) : *((uint8_t *)off_140C10 + 36);
    result = event_notify(v7 != 0, 512);
    v8 = result;
    if ( result )
    {
      *(uint8_t *)(result + 28) = *(uint8_t *)(v2 + 6489);
      *(uint8_t *)(result + 29) = *(uint8_t *)(v2 + 6488);
      *(uint8_t *)(result + 51) = 0;
      *(uint8_t *)(result + 53) = 0;
      if ( !a2 )
      {
        *(uint32_t *)(result + 88) = dword_140C0C;
        *(uint32_t *)(result + 92) = result;
      }
      hci_le_set_scan_params(result, 1, a2, v4);
      return ble_event_dispatch(v8, 3);
    }
  }
  return result;
}

