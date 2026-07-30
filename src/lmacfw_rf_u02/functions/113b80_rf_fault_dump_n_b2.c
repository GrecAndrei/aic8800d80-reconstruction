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

// rf_fault_dump_n_b2 @ 0x113b80, size 8 bytes
// Doc: rf_fault_dump_n_b2 [rf]: Dump RF fault state, iterating up to 0x5c entries
// rf_fault_dump_n_b2 [rf]: Dump RF fault state, iterating up to 0x5c entries
int  rf_fault_dump_n_b2(int a1)
{
  return host_reg_wait_set(2u, a1);
}

