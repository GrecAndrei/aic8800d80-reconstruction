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

extern uint32_t off_1148F8;
extern uint32_t off_1148FC;
extern uint32_t dword_114900;

// hci_tx_data @ 0x114898, size 96 bytes
// Doc: hci_tx_data [rf]: Configure RF channel/parameters from global state
// hci_tx_data [rf]: Configure RF channel/parameters from global state
int  hci_tx_data(int a1, int a2, unsigned int a3)
{
  int v6; // r4
  uint32_t v8[4]; // [sp+0h] [bp-50h] BYREF
  uint8_t v9[64]; // [sp+10h] [bp-40h] BYREF

  if ( !*(uint32_t *)off_1148F8 )
    ke_event_busy_check();
  MEMORY[0x1D8](*(uint32_t *)off_1148FC, 80, v8);
  if ( v8[0] != dword_114900 )
    return -1;
  v6 = a1 & v8[1];
  if ( !v6 )
    return 1;
  if ( (v6 & 1) != 0 )
  {
    memcpy_large(a2, v9, 64);
    if ( a3 <= 0x3F )
      return -2;
  }
  return 0;
}

