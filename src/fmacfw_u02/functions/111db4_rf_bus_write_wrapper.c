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

// rf_bus_write_wrapper @ 0x111db4, size 4 bytes
// Doc: rf_bus_write2_n19a [rf]: RF bus 2-word write handler variant n19a
// rf_bus_write2_n19a [rf]: RF bus 2-word write handler variant n19a
// attributes: thunk
int * rf_bus_write_wrapper(int *result, unsigned int a2)
{
  return sub_111D44(result, a2);
}

