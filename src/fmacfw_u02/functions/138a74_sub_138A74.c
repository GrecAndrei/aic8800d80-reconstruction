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

extern uint32_t dword_138AA4;

// tx_power_set @ 0x138a74, size 46 bytes
// Doc: sub_1238A74 [util]: Helper that calls sub-function with arg 4 and returns result
// sub_1238A74 [util]: Helper that calls sub-function with arg 4 and returns result
uint32_t ** tx_power_set(uint32_t *a1)
{
  int v1; // r5

  v1 = dword_138AA4;
  tx_power_lookup(0, 4, a1[5]);
  cmd_handler_c(v1, a1);
  cmd_handler_a(v1 - 8, a1);
  return load_and_process_r0((uint32_t **)(v1 - 32));
}

