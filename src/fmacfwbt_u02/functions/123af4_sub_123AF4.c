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

extern uint32_t dword_123B30;

// sub_123AF4 @ 0x123af4, size 60 bytes
int  sub_123AF4(int a1, uint8_t *a2, int a3, int a4)
{
  int v4; // r5
  int v6; // r0
  int v7; // r4

  v4 = dword_123B30 + 1320 * *a2;
  v6 = rf_bus_setup_n3a8(47, a4, a3, 2);
  *(uint8_t *)(v4 + 110) = a2[1];
  v7 = v6;
  message_dispatch_c7ac(v4);
  message_dispatch_n_4c4(v4, v7 + 1, v7);
  sub_12CBB4(v7);
  return 0;
}

