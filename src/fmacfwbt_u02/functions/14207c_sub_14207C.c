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

extern uint32_t dword_1420D0;
extern uint32_t dword_1420CC;

// lookup_phy_entry @ 0x14207c, size 80 bytes
// Doc: sub_124207C [util]: Generic helper, indexed buffer init (size 0x2b8)
// sub_124207C [util]: Generic helper, indexed buffer init (size 0x2b8)
int  lookup_phy_entry(int a1, int a2, char a3)
{
  int result; // r0
  uint16_t v5; // r3
  int v6; // r0
  int v7; // r1
  uint64_t v8; // r2
  int v9; // [sp+Ch] [bp-4h] BYREF

  result = hci_le_connection_update((int)&v9, dword_1420D0 + 1320 * a1, dword_1420CC + 696 * a2, 7, 0);
  if ( result )
  {
    v5 = result + 1;
    *(uint8_t *)(*(uint32_t *)(v9 + 72) + result + 108) = a3;
    v6 = v9;
    v7 = *(uint32_t *)(v9 + 76);
    LODWORD(v8) = *(uint32_t *)(v7 + 28) - 1 + v5;
    HIDWORD(v8) = v5 + 4;
    *(uint64_t *)(v7 + 32) = v8;
    return ble_event_dispatch(v6, 3);
  }
  return result;
}

