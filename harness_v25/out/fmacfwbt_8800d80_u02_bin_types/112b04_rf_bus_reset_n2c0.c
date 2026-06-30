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

// rf_bus_reset_n2c0 @ 0x112b04, size 48 bytes
// Doc: rf_fault_dump_n41f [rf]: Dumps RF fault state
// rf_fault_dump_n41f [rf]: Dumps RF fault state
uint8_t * rf_bus_reset_n2c0(int a1, int a2, int a3)
{
  uint8_t *result; // r0
  uint32_t *v4; // r2

  if ( (*((uint16_t *)rf_cmd_send_n_338_2b34 + 89) & 0x4000) != 0 )
    result = sub_10D60C((uint8_t *)rf_bus_reset_n300);
  else
    result = (uint8_t *)sub_12ECB0(rf_cmd_send_n_334, a2, a3);
  v4 = rf_cmd_send_n_32c;
  *(uint8_t *)rf_bus_reset_n2f8 = 0;
  v4[896] &= ~1u;
  return result;
}

