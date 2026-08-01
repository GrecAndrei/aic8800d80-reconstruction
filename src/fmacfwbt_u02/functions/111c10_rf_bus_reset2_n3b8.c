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

// rf_reg_write_alias @ 0x111c10, size 4 bytes
// Doc: rf_reg_write_alias [rf]: RF bus reset variant; clears state via helper with arg setup.
// rf_reg_write_alias [rf]: RF bus reset variant; clears state via helper with arg setup.
// attributes: thunk
int * rf_reg_write_alias(int *result, unsigned int a2)
{
  return rf_reg_write(result, a2);
}

