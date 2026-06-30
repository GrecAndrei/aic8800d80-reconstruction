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

extern uint32_t dword_11B630;

// scan_chan_entry_alloc_n_54 @ 0x11b5e8, size 72 bytes
// Doc: scan_chan_entry_alloc_n_54 [scan]: Allocate a 0x54-byte scan channel entry from pool
// scan_chan_entry_alloc_n_54 [scan]: Allocate a 0x54-byte scan channel entry from pool
int  scan_chan_entry_alloc_n_54(int a1, int a2)
{
  int v4; // r5
  int v5; // r8
  int v6; // r2

  v4 = dword_11B630 + 84 * a2;
  v5 = *(uint32_t *)(a1 + 76);
  sub_12D4F8(84 * (int16_t)a2 + 12 + dword_11B630);
  v6 = *(uint16_t *)(a1 + 4);
  --*(uint8_t *)(v4 + 80);
  if ( v6 )
    return sub_118358(a1, *(uint32_t *)(v5 + 72), a2);
  else
    return sub_119120();
}

