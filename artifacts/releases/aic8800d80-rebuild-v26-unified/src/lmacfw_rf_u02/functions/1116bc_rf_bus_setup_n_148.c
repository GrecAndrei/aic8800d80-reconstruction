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

// rf_bus_setup_n_148 @ 0x1116bc, size 4 bytes
// Doc: rf_bus_reset2_n3ba [rf]: Reset RF bus and initialize MMIO state
// rf_bus_reset2_n3ba [rf]: Reset RF bus and initialize MMIO state
// attributes: thunk
int * rf_bus_setup_n_148(int *result, unsigned int a2)
{
  return sub_11164C(result, a2);
}

