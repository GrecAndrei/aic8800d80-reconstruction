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

extern uint32_t dword_123400;
extern uint32_t dword_123404;

// sub_1233C8 @ 0x1233c8, size 56 bytes
// Doc: sub_12233C8 [mac]: Sends 0x85 message and arms timer via 0x70000010 register
// sub_12233C8 [mac]: Sends 0x85 message and arms timer via 0x70000010 register
int  sub_1233C8(int a1, int a2, int a3, int a4)
{
  uint8_t *v4; // r4
  unsigned int v5; // r0

  v4 = (uint8_t *)rf_bus_setup_n3a8(133, a4, a3, 1);
  v5 = sub_10EBDC(dword_123400, 1);
  *v4 = (BYTE2(v5) ^ 1) & 1;
  sub_12ECB0(dword_123404, v5, HIWORD(v5) & 1);
  sub_12CBB4(v4);
  return 0;
}

