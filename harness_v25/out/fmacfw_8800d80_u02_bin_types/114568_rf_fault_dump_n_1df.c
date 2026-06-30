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

// rf_fault_dump_n_1df @ 0x114568, size 6 bytes
// Doc: rf_fault_dump_n_1df [rf]: Dump RF fault state from shared trace buffer
// rf_fault_dump_n_1df [rf]: Dump RF fault state from shared trace buffer
int  rf_fault_dump_n_1df(int a1, int a2, int a3)
{
  return msg_parse(rf_fault_dump_n_1d8, a2, a3);
}

