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

// dummy_store_global @ 0x1146b8, size 10 bytes
// Doc: dummy_store_global [rf]: Clear a global RF status flag by zeroing word
// dummy_store_global [rf]: Clear a global RF status flag by zeroing word
void dummy_store_global()
{
  **(uint32_t **)rf_fault_dump_n_84 = **(uint32_t **)rf_fault_dump_n_84;
}

