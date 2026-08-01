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

// mem_free_ret @ 0x10f5bc, size 12 bytes
// Doc: mem_free_ret [rf]: Enable/init RF block and return status (split helper)
// mem_free_ret [rf]: Enable/init RF block and return status (split helper)
int  mem_free_ret(int a1, int a2)
{
  mem_free(a2);
  return 1;
}

