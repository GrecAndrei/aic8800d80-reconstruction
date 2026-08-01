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

extern uint32_t dword_119D54;

// util_scale_index @ 0x119d18, size 58 bytes
int  util_scale_index(int a1, uint8_t *a2, int a3, int a4)
{
  int v4; // r5
  int v6; // r6
  int v7; // r0
  int v8; // r5
  int v9; // r1
  int v10; // r4

  v4 = dword_119D54;
  v6 = 7 * *a2;
  v7 = ke_msg_send(47, a4, a3, 2);
  v8 = v4 + 32 * v6;
  v9 = (char)a2[1];
  v10 = v7;
  rf_set_temperature(v8, v9);
  rf_get_temperature(v8, v10 + 1, v10);
  rx_irq_handler(v10);
  return 0;
}

