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

// rf_fault_dump_n_1ec @ 0x11455c, size 6 bytes
// Doc: rf_fault_dump_n_1ec [rf]: RF fault dump entry referencing fault table
// rf_fault_dump_n_1ec [rf]: RF fault dump entry referencing fault table
int  rf_fault_dump_n_1ec(int a1, int a2, int a3)
{
  return msg_parse(rf_fault_dump_564, a2, a3);
}

