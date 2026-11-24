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


extern uint32_t dword_140DC0;

// clear_197750_buffer @ 0x140d9c, size 36 bytes
int clear_197750_buffer()
{
  int *v0; // r4
  int result; // r0

  v0 = (int *)dword_140DC0;
  rx_phy_status_parse(0xBu, 0);
  result = (int)memset(v0, 0, 0x1960u);
  v0[1620] = -1;
  return result;
}
