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

extern uint32_t dword_13C110;
extern uint32_t dword_13C114;

// lookup_interface_info @ 0x13c0a4, size 108 bytes
// Doc: sub_123C0A4 [util]: Boundary check: compare value against 0xff sentinel
// sub_123C0A4 [util]: Boundary check: compare value against 0xff sentinel
int  lookup_interface_info(int a1, int a2)
{
  int v3; // r7
  int v5; // r4

  if ( a2 == 255 )
    return 2;
  v3 = dword_13C110;
  v5 = *(uint8_t *)(696 * (uint8_t)a1 + 12 * (uint8_t)a2 + dword_13C110 + 453);
  return v5 == 33
      || rx_rate_field_parse((v5 << 8) | 8) != 1
      || *(uint16_t *)(dword_13C114 + 32 * v5 + 20) > ((*(uint16_t *)(v3 + 2 * (a2 + 348 * a1) + 316)
                                                              - *(uint16_t *)(*(uint32_t *)(dword_13C114 + 32 * v5 + 28) + 4))
                                                             & 0xFFFu);
}

