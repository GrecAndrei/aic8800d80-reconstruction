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

// rf_param_load_byte @ 0x119b2c, size 32 bytes
// Doc: rf_param_load_byte [util]: Load a single parameter byte and dispatch to handler
// rf_param_load_byte [util]: Load a single parameter byte and dispatch to handler
int  rf_param_load_byte(int a1, uint8_t *a2, int a3, int a4)
{
  lmac_table_lookup_n540(*a2);
  sub_11DED8(58, a4, a3);
  return 0;
}

