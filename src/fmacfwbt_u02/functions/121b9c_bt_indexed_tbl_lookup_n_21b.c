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

extern uint32_t dword_121BBC;

// phy_read_band @ 0x121b9c, size 32 bytes
// Doc: phy_read_band [bt]: Indexed lookup into 0x2b8-stride table; returns entry value minus 0x21
// phy_read_band [bt]: Indexed lookup into 0x2b8-stride table; returns entry value minus 0x21
BOOL  phy_read_band(int a1, int a2)
{
  return *(uint8_t *)(696 * a1 + 12 * a2 + dword_121BBC + 453) != 33;
}

