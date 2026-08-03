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

// rf_param_set_op2 @ 0x114570, size 10 bytes
// Doc: rf_param_set_op2 [rf]: Set RF parameter via opcode 2 with 12-byte payload
// rf_param_set_op2 [rf]: Set RF parameter via opcode 2 with 12-byte payload
int  rf_param_set_op2(int a1)
{
  return rf_init_or_config_n_318(2, a1, 0xCu);
}

