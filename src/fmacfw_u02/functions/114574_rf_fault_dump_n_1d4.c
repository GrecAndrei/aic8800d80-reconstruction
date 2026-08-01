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

// process_global_167204 @ 0x114574, size 40 bytes
// Doc: rf_fault_dump_n_1b5 [rf]: Dump/record RF fault status into trace buffer
// rf_fault_dump_n_1b5 [rf]: Dump/record RF fault status into trace buffer
int  process_global_167204(int a1, int a2, int a3)
{
  int result; // r0
  uint8_t *v4; // r3
  uint32_t *v5; // r1

  result = event_dispatch(rf_fault_dump_59c, a2, a3);
  v4 = rf_fault_dump_n_1a8;
  if ( *((uint8_t *)rf_fault_dump_n_1a8 + 3) )
  {
    v5 = rf_fault_dump_n_1a0;
    *(uint32_t *)rf_fault_dump_n_1a3 &= ~8u;
    *v5 &= 0xFFFFFFF0;
    v4[3] = 0;
    return 0;
  }
  return result;
}

