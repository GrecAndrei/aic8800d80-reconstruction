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

extern uint32_t dword_13C470;
extern uint32_t off_13C46C;
extern uint32_t dword_13C480;
extern uint32_t dword_13C47C;
extern uint32_t dword_13C474;
extern uint32_t off_13C478;

// lookup_tx_power_limit @ 0x13c424, size 70 bytes
// Doc: lookup_tx_power_limit [tx]: Lookup TX rate by index in 0x2b8-sized table, scale by 3*index, fetch int16 entry
// lookup_tx_power_limit [tx]: Lookup TX rate by index in 0x2b8-sized table, scale by 3*index, fetch int16 entry
int  lookup_tx_power_limit(int a1, int a2)
{
  int result; // r0
  unsigned int v3; // r4

  result = 696 * a1 + 12 * a2 + dword_13C470;
  v3 = *(uint8_t *)(result + 452);
  if ( **(int16_t **)off_13C46C < 0 && v3 > 0x20 )
    result = mmio_clear_register(dword_13C480, dword_13C47C, 1152);
  *(uint32_t *)(dword_13C474 + 32 * v3 + 8) = *((uint32_t *)off_13C478 + 4);
  return result;
}

