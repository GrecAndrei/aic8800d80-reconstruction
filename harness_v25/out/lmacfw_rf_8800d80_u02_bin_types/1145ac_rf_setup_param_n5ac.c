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

// rf_setup_param_n5ac @ 0x1145ac, size 10 bytes
// Doc: rf_setup_param_n5ac [rf]: Set up RF parameter (size=4, value=0x20)
// rf_setup_param_n5ac [rf]: Set up RF parameter (size=4, value=0x20)
int  rf_setup_param_n5ac(int a1)
{
  return rf_param_setup_44(8, a1, 4u);
}

